#ifndef PATRON_H
#define PATRON_H

//SECTION - Include necessary header files
#include "Book.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//SECTION - Patron Class Definition
class Patron {
    string name;
    int id;
    vector<Book*> borrowedBooks;
    public:
    Patron(string n, int i);
    string getName() const { return name; }
    int getId() const { return id; }
    void borrowBook(Book* b);
    void returnBook(Book* b);
    void displayPatron() const;
    bool operator==(const Patron& other) const;
    friend ostream& operator<<(ostream& os, const Patron& p);
    };

#endif