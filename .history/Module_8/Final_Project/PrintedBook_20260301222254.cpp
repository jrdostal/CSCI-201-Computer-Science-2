#include "Book.h"
#include <string>
#include "Library.h"
using namespace std;

class PrintedBook : public Book {
    Library management_system;
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