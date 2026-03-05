#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

using namespace std;

string genreToString(Genre g) {
    switch(g) {
        case Genre::Fiction: return "Fiction";
        case Genre::NonFiction: return "NonFiction";
        case Genre::Mystery: return "Mystery";
        case Genre::Science: return "Science";
        case Genre::Biography: return "Biography";
        default: return "Fiction";
    }
}

Library::Library() {
    loadData();
};

void Library::displayBooks() const {
    for (const Book* b : books) {
        cout << *b << endl;
    }
};

void Library::addBook(Book* b) {
    books.push_back(b);
    saveData();
    displayBooks();
};

void Library::displayPatrons() const {
    for (const Patron& p : patrons) {
        cout << p << endl;
    }
};

void Library::addPatron(const Patron& p) {
    patrons.push_back(p);
    saveData();
    displayPatrons();};

void Library::loadData() {
    // load book data from file
    std::ifstream file("books.txt");
    if (!file) throw std::runtime_error("Failed to open books file.");
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string genreStr, title, author, typeStr, extraStr;
        
        getline(ss, genreStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, typeStr, ',');
        getline(ss, extraStr, ',');

        Genre g = Genre::Fiction;
        if (genreStr == "NonFiction") g = Genre::NonFiction;
        else if (genreStr == "Mystery") g = Genre::Mystery;
        else if (genreStr == "Science") g = Genre::Science;
        else if (genreStr == "Biography") g = Genre::Biography;

        if (typeStr == "Printed") {
            books.push_back(new PrintedBook(title, author, g, stoi(extraStr)));
        } else if (typeStr == "EBook") {
            books.push_back(new EBook(title, author, g, stod(extraStr)));
        }
    }

    // load patron data from file
    std::ifstream patronFile("patrons.txt");
    if (!patronFile) throw std::runtime_error("Failed to open patrons file.");
    
    while (getline(patronFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, name;
        getline(ss, idStr, ',');
        getline(ss, name); // Read rest of line as name
        if (!idStr.empty() && !name.empty()) {
            patrons.emplace_back(name, stoi(idStr));
        }
    }

    // load transaction data from file
    std::ifstream transactionFile("transactions.txt");
    // Transactions are optional on first run, so don't throw if missing
    if (transactionFile) {
        while (getline(transactionFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string pidStr, bookTitle, dateStr;
            getline(ss, pidStr, ',');
            getline(ss, bookTitle, ',');
            getline(ss, dateStr);
            
            if (!pidStr.empty()) {
                transactions.push_back(new Transaction(stoi(pidStr), bookTitle));
            }
        }
    }
};

void Library::checkoutBook(int patronId, string title) {
    // find patron and book, update status, log transaction
    for (Book* b : books) {
        if (b->getTitle() == title) {
            if (b->getStatus() == BookStatus::Available) {
                b->setStatus(BookStatus::CheckedOut);
                // log transaction
                transactions.push_back(new Transaction(patronId, title));
                saveData();
                return;
            } else if (b->getStatus() == BookStatus::CheckedOut) {
                throw runtime_error("Book is already checked out.");
            } else {
                throw runtime_error("Book is not available.");
            }
        }
    }
    throw runtime_error("Book not found.");
};

void Library::returnBook(int patronId, string title) {
    for (Book* b : books) {
        if (b->getTitle() == title && b->getStatus() == BookStatus::CheckedOut) {
            b->setStatus(BookStatus::Available);
            // log transaction
            transactions.push_back(new Transaction(patronId, title, true));
            saveData();
            return;
        }
    }
    throw runtime_error("Book not found or not checked out.");
};

void Library::saveData() {
    // Use template for books
    saveToFile("books.txt", books, [](Book* b) {
        stringstream ss;
        ss << genreToString(b->getGenre()) << "," 
           << b->getTitle() << "," 
           << b->getAuthor() << ",";
        
        // We need to cast to access specific fields or use a virtual helper. 
        // For simplicity in this context, we check type via dynamic_cast or assume structure.
        // Since we don't have a virtual 'getType' or 'getExtra', we will just re-construct based on what we know.
        // Note: In a full implementation, Book should have a virtual toCSV() method.
        // Here we will just output basic info + type.
        if (auto pb = dynamic_cast<PrintedBook*>(b)) {
             // We can't easily access pageCount since it's private in PrintedBook and no getter.
             // Assuming we added getters or made Library a friend (Library IS a friend).
             ss << "Printed," << pb->pageCount;
        } else if (auto eb = dynamic_cast<EBook*>(b)) {
             ss << "EBook," << eb->fileSizeMB;
        }
        return ss.str();
    });

    // Use template for patrons
    saveToFile("patrons.txt", patrons, [](const Patron& p) {
        // Library is friend of Patron, so we can access private members
        return to_string(p.id) + "," + p.name;
    });

    // Use template for transactions
    saveToFile("transactions.txt", transactions, [](Transaction* t) {
        return to_string(t->patronId) + "," + t->bookTitle + "," + t->date;
    });
};

Library::~Library() {
    saveData();
    for (Book* b : books) {delete b;}
    for (Transaction *t : transactions) {delete t;}
    books.clear();
    patrons.clear();
    transactions.clear();
};

void Library::searchByAuthor(const string& author) const {
    cout << "Searching for author: " << author << endl;
    bool found = false;
    for (const Book* b : books) {
        if (b->getAuthor().find(author) != string::npos) {
            cout << *b << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found by this author." << endl;
}

void Library::searchByGenre(Genre genre) const {
    cout << "Searching for genre: " << genreToString(genre) << endl;
    for (const Book* b : books) {
        if (b->getGenre() == genre) {
            cout << *b << endl;
        }
    }
}