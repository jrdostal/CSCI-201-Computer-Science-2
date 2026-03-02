#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Patron {
    string name;
    int id;
    vector<Book*> borrowedBooks;
    public:
    Patron(string n, int i);
    void borrowBook(Book* b);
    void returnBook(Book* b);
    void displayPatron() const;
    bool operator==(const Patron& other) const;
    friend ostream& operator<<(ostream& os, const Patron& p);
    };

Patron::Patron(string n, int i) : name(n), id(i) {};

void Patron::borrowBook(Book* b) {
    borrowedBooks.push_back(b);
};

void Patron::returnBook(Book* b) {
    borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), b), borrowedBooks.end());
};

void Patron::displayPatron() const {
    cout << "Name: " << name << "\nID: " << id << endl;
    cout << "Borrowed Books:" << endl;
    for (const Book* b : borrowedBooks) {
        cout << *b << endl;
    }
};

bool Patron::operator==(const Patron& other) const {
    return name == other.name && id == other.id;
};

ostream& operator<<(ostream& os, const Patron& p) {
    p.displayPatron();
    return os;
};