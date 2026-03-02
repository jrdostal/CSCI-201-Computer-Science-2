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

Library::Library() {
    loadData();
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        string title = "Book " + to_string(i + 1);
        string author = "Author " + to_string(i + 1);
        Genre genre = static_cast<Genre>(rand() % 5);
        if (i % 2 == 0) {
            books.push_back(new PrintedBook(title, author, genre, 100 + i * 10));
        } else {
            books.push_back(new EBook(title, author, genre, 1.5 + i * 0.5));
        }
    }
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
    // parse and create Book objects
    try {
        Library.checkoutBook(int patronId, string title);
        Library.returnBook(int patronId, string title1);
    } catch (const std::exception& e) {
    cerr << "Error: " << e.what() << endl;
    }
    // TODO: Implement file parsing logic
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
    ofstream file("books.txt");
    if (!file) throw runtime_error("Failed to open books file for writing.");
    // write book data to file

    ofstream patronFile("patrons.txt");
    if (!patronFile) throw runtime_error("Failed to open patrons file for writing.");
    // write patron data to file

    ofstream transactionFile("transactions.txt");
    if (!transactionFile) throw runtime_error("Failed to open transactions file for writing.");
    // write transaction data to file
};

Library::~Library() {
    saveData();
    for (Book* *b : books) {delete b;}
    for (Patron *p : patrons) {delete p;}
    for (Book* b : books) {delete b;}
    for (Transaction *t : transactions) {delete t;}
    books.clear();
    patrons.clear();
    transactions.clear();
};