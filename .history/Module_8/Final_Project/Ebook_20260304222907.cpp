//SECTION - Include necessary header files
#include <iostream>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "EBook.h"

//SECTION - Constructor for the EBook class
//Uses the Book base class to create a Book of type EBook
EBook::EBook(string t, string a, Genre g, double size) : Book(g, t, a, BookType::EBook, 0), fileSizeMB(size) {};

//SECTION - Display Information function
// This function uses the Book base class's function to display the EBook's info, adding File Size using the getFileSize function
void EBook::displayInfo() const {
    Book::displayInfo();
    cout << "File Size: " << EBook::getFileSize() << " MB" << endl;
};

//SECTION - Get file size function
// This function returns the file size of the EBook
double EBook::getFileSize() const {
    return fileSizeMB;
};

//SECTION - Destructor for the EBook class
EBook::~EBook() {};