#ifndef PATRON_H
#define PATRON_H

//SECTION - Include necessary header files
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"

//SECTION - Patron Class Definition
class Patron {

    //SECTION - Private Data Members for the Patron class
    // Data members for the patron name and ID
    string name;
    int id;

    // Vector to hold the list of books borrowed by a patron
    vector<Book*> borrowedBooks;

    //SECTION - Public members for interface and functionality
    public:

        // Constructor for Patron class
        Patron(string n, int i);

        // Destructor for Patron class
        ~Patron() {};

        // Getter for the patron's name
        string getName() const { return name; }

        // Getter for the patron's name
        int getId() const { return id; }

        // function to borrow a book from the library inventory
        void borrowBook(Book* b);

        // function to return a book to the library inventory
        void returnBook(Book* b);

        // function to display a patron's information
        void displayPatron() const;

        // overload == operator to compare two patrons' info
        bool operator==(const Patron& other) const;

        // overload << operator to display patron info using cout
        friend ostream& operator<<(ostream& os, const Patron& p);
    };

//SECTION - End of header guard
#endif