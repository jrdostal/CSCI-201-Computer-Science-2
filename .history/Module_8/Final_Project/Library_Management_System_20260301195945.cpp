/*
Project Title: Library Management System
Project Overview
This project simulates a small Library Management System that manages books,
patrons, and transactions (borrowing and returning). It demonstrates OOP design and
advanced C++ features in an integrated, real-world context.
This C++ project and design requires: four or more classes, OOP principles
(inheritance, polymorphism, encapsulation), operator overloading, exception
handling, collections, file I/O, and enumerations.
Core Object-Oriented Requirements
Concept Implementation
Classes (4+) Book, Patron, Transaction, Library, and optionally Date
Inheritance EBook and PrintedBook inherit from Book
Polymorphism Book has virtual methods (e.g., displayInfo()) overridden by
child classes
Operator
Overloading
Overload == and << for Book and Patron
Exception Handling Handle invalid input, missing files, and invalid transactions
Collections Use std::vector, std::map for storing books and patrons
File I/O Load and save book and patron data from .txt or .csv files
Enumerations Define Genre and BookStatus enums
Other Constructs const correctness, dynamic memory, iterators, and function
templates (optional)
M08A Final Project: Library Management System
Additional Required Features
● Implement a menu-driven interface for user interaction.
● Add search by author or genre.
● Use templates for file save/load operations.
● Add a date/time class for due dates.

Example Functional Flow
1. The project should load books and patrons from text (csv) files.
2. User can:
○ View all books and patrons
○ Check out or return books of a valid patron
○ Add new books or patrons
3. All transactions are logged in a file.
4. Errors such as missing books, invalid IDs, or unavailable books trigger
exceptions.
Example File I/O
Books.txt (you are required to add additional books)
Fiction,The Great Gatsby,F. Scott Fitzgerald,Printed,180
Science,Quantum Physics 101,Albert Einstein,EBook,4.5
Patrons.txt (you are required to add additional patrons)
1,Jane Doe
2,John Smith
M08A Final Project: Library Management System
File Operations Example
*/

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
        library.checkoutBook(1, "The Great Gatsby");
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

int main() {
    Library library;
    try {
    library.loadData();
    library.displayBooks();
    library.displayPatrons();
    library.checkoutBook(1, "The Great Gatsby");
    library.returnBook(1, "The Great Gatsby");
    library.saveData();
    }
    catch (const std::exception& e) {
    cerr << "Application Error: " << e.what() << endl;
    }
    return 0;
};