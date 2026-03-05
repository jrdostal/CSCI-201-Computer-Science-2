//SECTION - Include necessary header files
#include "Book.h"
#include "PrintedBook.h"
#include <string>
#include <iostream>

using namespace std;

//SECTION - PrintedBook Constructor
PrintedBook::PrintedBook(Genre g, string t, string a, int pages) : Book(t, a, g, BookType::Printed), pageCount(pages) {};

Book(Genre g, string t, string a, BookType bt, int p

//SECTION - Display Information Method
void PrintedBook::displayInfo() const {
    Book::displayInfo();
    cout << "Page Count: " << pageCount << endl;
};