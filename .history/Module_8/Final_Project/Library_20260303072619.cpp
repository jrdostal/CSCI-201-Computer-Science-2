//SECTION - Include necessary header files
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

//SECTION - Helper function to convert Genre enum to string
string genreToString(Genre g) {
    //Switch statement to
    switch(g) {
        case Genre::Fiction: return "Fiction";
        case Genre::NonFiction: return "NonFiction";
        case Genre::Mystery: return "Mystery";
        case Genre::Science: return "Science";
        case Genre::Biography: return "Biography";
        default: return "Fiction";
    }
}

//SECTION - Library Constructor
Library::Library() {
    loadData();
};

//SECTION - Display Methods
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
    for (const auto& pair : patrons) {
        cout << pair.second << endl;
    }
};

//SECTION - Add Patron Method
void Library::addPatron(const Patron& p) {
    patrons.emplace(p.getId(), p);
    saveData();
    displayPatrons();
};

//SECTION - Load Data Method
void Library::loadData() {
    //SECTION - Load book data from file
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

    //SECTION - Load patron data from file
    std::ifstream patronFile("patrons.txt");
    if (!patronFile) throw std::runtime_error("Failed to open patrons file.");

    while (getline(patronFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, name;
        getline(ss, idStr, ',');
        getline(ss, name); // Read rest of line as name
        if (!idStr.empty() && !name.empty()) {
            int id = stoi(idStr);
            patrons.emplace(id, Patron(name, id));
        }
    }

    //SECTION - Load transaction data from file
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

//SECTION - Checkout Book Method
void Library::checkoutBook(int patronId, string title) {
    // Validate patron exists
    if (patrons.find(patronId) == patrons.end()) {
        throw runtime_error("Patron ID not found.");
    }
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

//SECTION - Return Book Method
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

//SECTION - Save Data Method
void Library::saveData() {
    //SECTION - Save books using template
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
             ss << "Printed," << pb->getPageCount();
        } else if (auto eb = dynamic_cast<EBook*>(b)) {
             ss << "EBook," << eb->getFileSize();
        }
        return ss.str();
    });

    //SECTION - Save patrons using template
    saveToFile("patrons.txt", patrons, [](const pair<const int, Patron>& pair) {
        const Patron& p = pair.second;
        return to_string(p.getId()) + "," + p.getName();
    });

    //SECTION - Save transactions using template
    saveToFile("transactions.txt", transactions, [](Transaction* t) {
        return to_string(t->patronId) + "," + t->bookTitle + "," + t->date;
    });
};

//SECTION - Library Destructor
Library::~Library() {
    saveData();
    for (Book* b : books) {delete b;}
    for (Transaction *t : transactions) {delete t;}
    books.clear();
    patrons.clear();
    transactions.clear();
};

//SECTION - Search Methods
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