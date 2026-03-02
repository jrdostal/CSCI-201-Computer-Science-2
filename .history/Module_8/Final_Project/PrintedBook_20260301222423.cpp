#include "Book.h"
#include "PrintedBook.h"
#include <string>
#include <iostream>

using namespace std;

class PrintedBook : public Book {
    int pageCount;
    public:
        PrintedBook(string t, string a, Genre g, int pages);
        void displayInfo() const override;
    };

PrintedBook::PrintedBook(string t, string a, Genre g, int pages) : Book(t, a, g), pageCount(pages) {};

void PrintedBook::displayInfo() const {
    Book::displayInfo();
    cout << "Page Count: " << pageCount << endl;
};