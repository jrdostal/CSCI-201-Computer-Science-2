//SECTION - Include necessary header files
#include <iostream>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "EBook.h"

//SECTION - Constructor for the EBook class
//Uses the Book base class to create a Book of type EBook
EBook::EBook(string t, string a, Genre g, int p, double size) : Book(t, a, g, BookType::EBook, p), fileSizeMB(size) {};

//SECTION - Display Information Method
// Displays 
void EBook::displayInfo() const {
    Book::displayInfo();
    cout << "File Size: " << fileSizeMB << " MB" << endl;
};

//SECTION - Get file size function
double EBook::getFileSize() const {
    return fileSizeMB;
};

//SECTION - Destructor for the EBook class
EBook::~EBook() {};