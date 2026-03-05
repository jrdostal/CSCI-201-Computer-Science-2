#ifndef EBOOK_H
#define EBOOK_H

//SECTION - Include necessary header files
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

//SECTION - EBook Class Definition
class EBook : public Book {
    double fileSizeMB;
    public:
        EBook(string t, string a, Genre g, int p, double size) : Book(t, a, g, BookType::EBook, p), fileSizeMB(size) {};
        ~EBook();
        void displayInfo() const override;
        double getFileSize() const { return fileSizeMB; }
};

#endif