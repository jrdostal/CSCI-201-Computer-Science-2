#include "Book.h"
#include <string>
using namespace std;

class PrintedBook : public Book {
    M08A Final Project: Library Management System
    int pageCount;
    public:
        PrintedBook(std::string t, std::string a, Genre g, int pages);
        void displayInfo() const override;
    };