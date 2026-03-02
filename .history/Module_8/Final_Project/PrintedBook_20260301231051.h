#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

class PrintedBook : public Book {
    int pageCount;
    public:
        PrintedBook(string t, string a, Genre g, int pages);
        void displayInfo() const override;
    };

#endif