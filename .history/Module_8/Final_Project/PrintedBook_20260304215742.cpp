//SECTION - Include necessary header files
#include "Book.h"
#include "PrintedBook.h"
#include <string>
#include <iostream>

using namespace std;

//SECTION - PrintedBook Constructor
PrintedBook::PrintedBook(Genre g, string t, string a, string bt, int p) : Book(g, t, a, BookType::Printed, getPageCount()) {};

//SECTION - Display Information Method
void PrintedBook::displayInfo() const {
    Book::displayInfo();
    cout << "Page Count: " << pageCount << endl;
};

int getPageCount() {

    pageCount = Book::getPageCount();

    return pageCount;

}

//SECTION - PrintedBook Destructor
PrintedBook::~PrintedBook() {};