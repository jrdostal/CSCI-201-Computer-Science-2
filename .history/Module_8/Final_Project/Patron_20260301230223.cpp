#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

Patron::Patron(string n, int i) : name(n), id(i) {};

void Patron::borrowBook(Book* b) {
    borrowedBooks.push_back(b);
};

void Patron::returnBook(Book* b) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), b);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    } else {
        throw runtime_error("Book not found in list of borrowed books.");
    }
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