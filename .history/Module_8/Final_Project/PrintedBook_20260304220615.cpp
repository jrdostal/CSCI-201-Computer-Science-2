//SECTION - Include necessary header files
#include <iostream>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "PrintedBook.h"

//SECTION - PrintedBook Constructor
// Constructor for the PrintedBook class
PrintedBook::PrintedBook(Genre g, string t, string a, string bt, int p) : Book(g, t, a, BookType::Printed, getPageCount()) {};

//SECTION - Display Information Method
void PrintedBook::displayInfo() const {
    // Uses the display info function from the Book base class to display the book's info. Also add's the page count for the book.
    Book::displayInfo();
    cout << "Page Count: " << pageCount << endl;
};

//SECTION - PrintedBook Destructor
// Destructor for the PrintedBook class
PrintedBook::~PrintedBook() {};