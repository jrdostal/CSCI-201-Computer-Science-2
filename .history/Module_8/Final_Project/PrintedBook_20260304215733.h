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
    protected:
        int pageCount;
    public:
        PrintedBook(Genre g, string t, string a, string bt, int p);
        ~PrintedBook();
        int getPageCount() const {};
        void displayInfo() const override;
    };

#endif