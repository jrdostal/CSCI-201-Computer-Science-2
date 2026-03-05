#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

//SECTION - Include necessary header files
#include <string>
#include <iostream>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"

//SECTION - PrintedBook Class Definition
class PrintedBook : public Book {

    //SECTION - Public members for interface and functionality
    public:

        //Constructor for the PrintedBook class
        PrintedBook(string t, string a, Genre g, int p);

        //Destructor for the PrintedBook class
        ~PrintedBook();

        //Function to display the book's information
        void displayInfo() const override;
    };

//SECTION - End of header guard
#endif