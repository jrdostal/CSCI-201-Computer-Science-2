#include "Book.h"
#include "EBook.h"
#include <iostream>
#include <string>

using namespace std;

class EBook : public Book {
    double fileSizeMB;
    public:
        EBook(string t, string a, Genre g, double size);
        void displayInfo() const override;
    };

EBook::EBook(string t, string a, Genre g, double size) : Book(t, a, g), fileSizeMB(size) {};

void EBook::displayInfo() const {
    Book::displayInfo();
    cout << "File Size: " << fileSizeMB << " MB" << endl;
};