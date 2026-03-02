#include "Book.h"
#include "PrintedBook.h"
#include <string>
#include <iostream>

using namespace std;

PrintedBook::PrintedBook(string t, string a, Genre g, int pages) : Book(t, a, g, BookType::Printed), pageCount(pages) {};

void PrintedBook::displayInfo() const {
    Book::displayInfo();
    cout << "Page Count: " << pageCount << endl;
};