//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"


//SECTION - Definition of the main function
int main() {
    //SECTION - Initialize Library
    Library library;

    //SECTION - Menu-driven interface for user interaction
    // The menu allows users to view books/patrons, check out/return books, add patrons, search by author/genre, and exit.
    // Variable to store user choice in the menu
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