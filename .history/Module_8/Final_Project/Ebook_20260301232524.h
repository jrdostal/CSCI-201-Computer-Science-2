#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

class EBook : public Book {
    double fileSizeMB;
    public:
        EBook(string t, string a, Genre g, double size);
        double getFileSize() const { return fileSizeMB; }
        void displayInfo() const override;
    };

#endif