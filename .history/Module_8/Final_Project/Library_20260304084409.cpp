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

//SECTION - Library Constructor
//Constructor for the Library class
Library::Library() {

    //Loads data from the books.txt, patrons.txt, and transactions.txt files using the loadData function
    loadData();
};

//SECTION - Display Books function
void Library::displayBooks() const {

    // Display all books in the library
    cout << "Books in Library:" << endl;

    // Loop to display books
    for (const Book* b : books) {
        cout << *b << endl;
    }
};

//SECTION - Add Book function
void Library::addBook(Book* b) {

    // Add a new book to the library
    books.push_back(b);

    // Uses saveData function to save list of books
    saveData();

    // Uses displayBooks function to display list of books after saving changes
    displayBooks();
};

//SECTION - Display Patrons function
void Library::displayPatrons() const {

    // Display all patrons in the library
    cout << "Patrons in Library:" << endl;

    // Loop to display patrons
    for (const auto& pair : patrons) {
        cout << pair.second << endl;
    }
};

//SECTION - Add Patron Method
void Library::addPatron(const Patron& p) {

    // Add a new patron to the library
    patrons.emplace(p.getId(), p);

    // Uses saveData function to save list of patrons
    saveData();

    // Uses displayPatrons function to display list of patrons after saving changes
    displayPatrons();
};

//SECTION - Load Data Method
void Library::loadData() {

    //SECTION - Load book data from file
    // Open books.txt data file using filestream. If the file does not open, throw an exception.
    std::ifstream file("books.txt");
    if (!file) throw std::runtime_error("Failed to open books file.");

    // Variable to hold data from the file
    string line;

    // Loop to read data from the file
    while (getline(file, line)) {

        // Validate if the file is empty. If the file is empty, continue loading data. If the file is not empty, displays the contents of the file and exits the program.
        if (line.empty() == true) continue;
        else if (line.empty() == false) {
            cout << "File is not empty. File contains: " << string(line) << endl;
            cout << "Exiting program" << endl;
            exit(1);
        };

        // Read data from the file and store it in the temporary variable.
        stringstream ss(line);

        // Variables to format/parse data from the file into the data members for the book class.
        string genreStr, title, author, typeStr, extraStr;

        // Parse data from temporarily stored data into data members from the book class
        getline(ss, genreStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, typeStr, ',');
        getline(ss, extraStr, ',');

        // Variable to temporarily store genre from data file
        Genre g = Genre::Fiction;

        // If statements to determine the genre of the book
        if (genreStr == "NonFiction") g = Genre::NonFiction;
        else if (genreStr == "Mystery") g = Genre::Mystery;
        else if (genreStr == "Science") g = Genre::Science;
        else if (genreStr == "Biography") g = Genre::Biography;
        else if (genreStr == "Fiction") g = Genre::Fiction;

        // If statements to determine the type of the book
        if (typeStr == "Printed") {
            books.push_back(new PrintedBook(title, author, g, stoi(extraStr)));
        } else if (typeStr == "EBook") {
            books.push_back(new EBook(title, author, g, stod(extraStr)));
        }
    }

    //SECTION - Load patron data from file
    std::ifstream patronFile("patrons.txt");

    // Open patrons.txt data file using filestream. If the file does not open, throw an exception.
    if (!patronFile) throw std::runtime_error("Failed to open patrons file.");

    // Loop to read data from the file
    while (getline(patronFile, line)) {

        // Validate if the file is empty. If the file is empty, continue loading data. If the file is not empty, displays the contents of the file and exits the program.
        if (line.empty() == true) continue;
        else if (line.empty() == false) {
            cout << "File is not empty. File contains: " << string(line) << endl;
            cout << "Exiting program" << endl;
            exit(1);
        };

        // Read data from the file and store it in the temporary variable.
        stringstream ss(line);

        // Variables to format/parse data from the file into the data members for the patron class.
        string idStr, name;

        // Parse data from temporarily stored data into data members from the patron class
        getline(ss, idStr, ',');

        // Read rest of line as name
        getline(ss, name);
        if (!idStr.empty() && !name.empty()) {
            int id = stoi(idStr);
            patrons.emplace(id, Patron(name, id));
        }
    }

    //SECTION - Load transaction data from file
    std::ifstream transactionFile("transactions.txt");

    // Transactions are optional on first run, so don't throw if missing
    if (transactionFile) {

        // Loop to read data from the file
        while (getline(transactionFile, line)) {

            // Validate if the file is empty. If the file is empty, continue loading data. If the file is not empty, displays the contents of the file and exits the program.
            if (line.empty() == true) continue;
            else if (line.empty() == false) {
                cout << "File is not empty. File contains: " << string(line) << endl;
                cout << "Exiting program" << endl;
                exit(1);
            };

            // Read data from the file and store it in the temporary variable.
            stringstream ss(line);

            // Variables to format/parse data from the file into the data members for the transaction class.
            string pidStr, bookTitle, dateStr;

            // Parse data from temporarily stored data into data members from the transaction class
            getline(ss, pidStr, ',');
            getline(ss, bookTitle, ',');
            getline(ss, dateStr);

            // If the transactions file is not empty, add a new transaction at the end of the file.
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

    // Loop to find patron and book, update book status, and log transaction.
    for (Book* b : books) {

        // Validate the book exists in the library
        if (b->getTitle() == title) {

            // Validate status of book. If not checked out, changes status to checked out.
            if (b->getStatus() == BookStatus::Available) {
                b->setStatus(BookStatus::CheckedOut);
                // Log transaction showing change from available to checked out.
                transactions.push_back(new Transaction(patronId, title));
                saveData();
                return;
            }

            // If book is already checked out, throw an exception stating the book is already checked out.
            else if (b->getStatus() == BookStatus::CheckedOut) {
                throw runtime_error("Book is already checked out.");
            }
            
            // If book is not available, throw an exception stating the book is not available.
            else {
                throw runtime_error("Book is not available.");
            }
        }
    }

    // If the book does not exist in the library, throw an exception stating the book cannot be found.
    throw runtime_error("Book not found in library inventory.");
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