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

    //SECTION - Loop to display menu and process user input until exit option is chosen
    // The loop continues until the user selects the exit option (choice 8).
    do {
        // Display menu options
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

        //SECTION - Input validation for menu choice
        // If the input is not an integer, clear the error state and ignore the rest of the line, then continue to the next iteration of the loop to prompt again.
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        // Clear the input buffer after reading the choice to ensure subsequent inputs are processed correctly.
        cin.ignore();

        //SECTION - Process user choice using a switch statement
        // Each case corresponds to a menu option and calls the appropriate method on the Library object.
        // The try-catch block is used to handle any exceptions that may arise during the execution of the chosen operation, such as file I/O errors or invalid input.
        try {
            //SECTION - Switch statement to handle user choices and call corresponding Library methods
            switch (choice) {
                // Each case corresponds to a menu option and calls the appropriate method on the Library object.
                //Case 1: Display all books in the library
                case 1:
                    library.displayBooks();
                    break;
                //Case 2: Display all patrons registered in the library
                case 2:
                    library.displayPatrons();
                    break;
                //Case 3: Checkout a book for a patron by ID and book title
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
                //Case 4: Return a book for a patron by ID and book title
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
                //Case 5: Add a new patron to the library by entering their name and ID
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
                //Case 6: Search for books by a specific author and display results
                case 6: {
                    string author;
                    cout << "Enter Author Name: ";
                    getline(cin, author);
                    library.searchByAuthor(author);
                    break;
                }
                //Case 7: Search for books by genre and display results
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
                //Case 8: Exit the program, saving data before exiting
                case 8:
                    cout << "Saving and Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } 
        //SECTION - Catch block to handle exceptions that may occur during library operations
        // If an exception is thrown during any of the library operations (e.g., file I/O errors, invalid input), it will be caught here and an error message will be displayed to the user.
        catch (const exception& e) {
            //Display error message to the user if an exception occurs during library operations
            cerr << "Error: " << e.what() << endl;
        }
    } 
    // The loop continues until the user selects the exit option (choice 8).
    while (choice != 8);

    //SECTION - Return 0 to indicate successful program termination
    //End program
    return 0;
};