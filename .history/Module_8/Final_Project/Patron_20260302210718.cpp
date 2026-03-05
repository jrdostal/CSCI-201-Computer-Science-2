//SECTION - Include necessary header files
#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

//SECTION - Patron Constructor
Patron::Patron(string n, int i) : name(n), id(i) {};

//SECTION - Borrow Book Method
void Patron::borrowBook(Book* b) {
    borrowedBooks.push_back(b);
};

//SECTION - Return Book Method
void Patron::returnBook(Book* b) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), b);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    } else {
        throw runtime_error("Book not found in list of borrowed books.");
    }
};

//SECTION - Display Patron Method
void Patron::displayPatron() const {
    cout << "Name: " << name << "\nID: " << id << endl;
    cout << "Borrowed Books:" << endl;
    for (const Book* b : borrowedBooks) {
        cout << *b << endl;
    }
};

//SECTION - Operator Overloading
bool Patron::operator==(const Patron& other) const {
    return name == other.name && id == other.id;
};

ostream& operator<<(ostream& os, const Patron& p) {
    p.displayPatron();
    return os;
};