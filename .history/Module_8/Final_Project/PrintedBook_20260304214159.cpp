//SECTION - Include necessary header files
#include "Book.h"
#include "PrintedBook.h"
#include <string>
#include <iostream>

using namespace std;

//SECTION - PrintedBook Constructor
PrintedBook::PrintedBook(Genre g, string t, string a, int pages) : Book(t, a, g, BookType::Printed), pageCount(pages) {};

genre(g),title(t), author(a), type(bt), status(BookStatus::Available), pageCount(p), dueDate(1, 1, 2024), dueTime(12, 0)

//SECTION - Display Information Method
void PrintedBook::displayInfo() const {
    Book::displayInfo();
    cout << "Page Count: " << pageCount << endl;
};