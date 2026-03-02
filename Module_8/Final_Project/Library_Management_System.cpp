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

#include <stdexcept>
#include <string>

#include "Book.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

using namespace std;

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