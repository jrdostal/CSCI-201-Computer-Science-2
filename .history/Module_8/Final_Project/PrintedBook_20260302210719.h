#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

//SECTION - Include necessary header files
#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

//SECTION - PrintedBook Class Definition
class PrintedBook : public Book {
    int pageCount;
    public:
        PrintedBook(string t, string a, Genre g, int pages);
        int getPageCount() const { return pageCount; }
        void displayInfo() const override;
    };

#endif