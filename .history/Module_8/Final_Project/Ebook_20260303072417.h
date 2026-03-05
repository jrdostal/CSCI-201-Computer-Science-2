#ifndef EBOOK_H
#define EBOOK_H

//SECTION - Include necessary header files
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

//SECTION - EBook Class Definition
class EBook : public Book {
    //SECTION - Data member to store the file size of the EBook
    double fileSizeMB;

    //SECTION - Public members for interface and functionality
    public:
        //Constructor for the EBook class
        EBook(string t, string a, Genre g, int p, double size);
        //Destructor for the EBook class
        ~EBook();
        //function to display the EBook's information
        void displayInfo() const override;
        //function to return the file size of the EBook
        double getFileSize() const { return fileSizeMB; }
};

#endif