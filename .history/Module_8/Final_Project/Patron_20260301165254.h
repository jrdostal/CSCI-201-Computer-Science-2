#include "Book.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Patron {
    std::string name;
    int id;
    std::vector<Book*> borrowedBooks;
    public:
    Patron(std::string n, int i);
    void borrowBook(Book* b);
    void returnBook(Book* b);
    void displayPatron() const;
    bool operator==(const Patron& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Patron& p);
    };