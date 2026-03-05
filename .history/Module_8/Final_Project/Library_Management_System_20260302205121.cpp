// Project Title: Library Management System
// Project Overview
// This project simulates a small Library Management System that manages books,
// patrons, and transactions (borrowing and returning). It demonstrates OOP design and
// advanced C++ features in an integrated, real-world context.
// This C++ project and design requires: four or more classes, OOP principles
// (inheritance, polymorphism, encapsulation), operator overloading, exception
// handling, collections, file I/O, and enumerations.
// Core Object-Oriented Requirements
// Concept Implementation
// Classes (4+) Book, Patron, Transaction, Library, and optionally Date
// Inheritance EBook and PrintedBook inherit from Book
// Polymorphism Book has virtual methods (e.g., displayInfo()) overridden by
// child classes
// Operator
// Overloading
// Overload == and << for Book and Patron
// Exception Handling Handle invalid input, missing files, and invalid transactions
// Collections Use std::vector, std::map for storing books and patrons
// File I/O Load and save book and patron data from .txt or .csv files
// Enumerations Define Genre and BookStatus enums
// Other Constructs const correctness, dynamic memory, iterators, and function
// templates (optional)
// M08A Final Project: Library Management System
// Additional Required Features
// - Implement a menu-driven interface for user interaction.
// - Add search by author or genre.
// - Use templates for file save/load operations.
// - Add a date/time class for due dates.
//
// Example Functional Flow
// 1. The project should load books and patrons from text (csv) files.
// 2. User can:
// o View all books and patrons
// o Check out or return books of a valid patron
// o Add new books or patrons
// 3. All transactions are logged in a file.
// 4. Errors such as missing books, invalid IDs, or unavailable books trigger
// exceptions.
// Example File I/O
// Books.txt (you are required to add additional books)
// Fiction,The Great Gatsby,F. Scott Fitzgerald,Printed,180
// Science,Quantum Physics 101,Albert Einstein,EBook,4.5
// Patrons.txt (you are required to add additional patrons)
// 1,Jane Doe
// 2,John Smith
// M08A Final Project: Library Management System
// File Operations Example

//!SECTION: The main function initializes the library, loads data, performs transactions, and saves data.

//SECTION - Include necessary header files

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
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. View All Books\n";
        cout << "2. View All Patrons\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Add Patron\n";
        cout << "6. Search by Author\n";
        cout << "7. Search by Genre\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(); // consume newline

        try {
            switch (choice) {
                case 1:
                    library.displayBooks();
                    break;
                case 2:
                    library.displayPatrons();
                    break;
                case 3: {
                    int pid;
                    string title;
                    cout << "Enter Patron ID: ";
                    cin >> pid;
                    cin.ignore();
                    cout << "Enter Book Title: ";
                    getline(cin, title);
                    library.checkoutBook(pid, title);
                    break;
                }
                case 4: {
                    int pid;
                    string title;
                    cout << "Enter Patron ID: ";
                    cin >> pid;
                    cin.ignore();
                    cout << "Enter Book Title: ";
                    getline(cin, title);
                    library.returnBook(pid, title);
                    break;
                }
                case 5: {
                    string name;
                    int id;
                    cout << "Enter Patron Name: ";
                    getline(cin, name);
                    cout << "Enter Patron ID: ";
                    cin >> id;
                    library.addPatron(Patron(name, id));
                    break;
                }
                case 6: {
                    string author;
                    cout << "Enter Author Name: ";
                    getline(cin, author);
                    library.searchByAuthor(author);
                    break;
                }
                case 7: {
                    // Simplified genre selection for demo
                    cout << "Genres: 0:Fiction, 1:NonFiction, 2:Mystery, 3:Science, 4:Biography\n";
                    int g;
                    cout << "Enter Genre ID: ";
                    cin >> g;
                    if (g >= 0 && g <= 4) library.searchByGenre(static_cast<Genre>(g));
                    else cout << "Invalid genre.\n";
                    break;
                }
                case 8:
                    cout << "Saving and Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 8);

    return 0;
};