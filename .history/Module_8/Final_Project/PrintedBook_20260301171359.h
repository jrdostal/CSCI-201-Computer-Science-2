#include "Book.h"
#include <string>
using namespace std;

class PrintedBook : public Book {
    Library management_system;
    int pageCount;
    public:
        PrintedBook(string t, string a, Genre g, int pages);
        void displayInfo() const override;
    };