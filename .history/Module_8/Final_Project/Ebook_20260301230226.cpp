#include "Book.h"
#include "EBook.h"
#include <iostream>
#include <string>

using namespace std;

EBook::EBook(string t, string a, Genre g, double size) : Book(t, a, g, BookType::EBook), fileSizeMB(size) {};

void EBook::displayInfo() const {
    Book::displayInfo();
    cout << "File Size: " << fileSizeMB << " MB" << endl;
};