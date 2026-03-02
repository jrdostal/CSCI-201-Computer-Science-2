#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include "Book.h"
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

void Library::loadData() {
    // load book data from file
    std::ifstream file("books.txt");
    if (!file) throw std::runtime_error("Failed to open books file.");
    // parse and create Book objects
    try {
        Library.checkoutBook(1, "The Great Gatsby");
    } catch (const std::exception& e) {
    cerr << "Error: " << e.what() << endl;
    }
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
    for (Transaction *t : transactions) {delete t;}
    books.clear();
    patrons.clear();
    transactions.clear();
}
void Library::addBook(Book* b) {}
void Library::addPatron(const Patron& p) {}
void Library::checkoutBook(int patronId, string title) {}
void Library::returnBook(int patronId, string title) {}
void Library::displayBooks() const {}
void Library::displayPatrons() const {}
