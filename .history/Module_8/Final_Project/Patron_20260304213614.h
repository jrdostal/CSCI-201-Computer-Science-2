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


using namespace std;


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

        // Function to
        string getName() const { return name; }
        int getId() const { return id; }
        void borrowBook(Book* b);
        void returnBook(Book* b);
        void displayPatron() const;
        bool operator==(const Patron& other) const;
        friend ostream& operator<<(ostream& os, const Patron& p);
    };

#endif