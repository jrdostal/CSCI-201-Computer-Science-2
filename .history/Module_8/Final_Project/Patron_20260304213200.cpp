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
    // Add book record to list of books borrowed by a patron
    borrowedBooks.push_back(b);
};

//SECTION - Return Book Method
// Remove book record from list of books borrowed by a patron
void Patron::returnBook(Book* b) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), b);
    // Validate if all books have been returned by patron
    if (it != borrowedBooks.end()) {

        // If all books have not been returned, remove book being returned from list of borrowed books
        borrowedBooks.erase(it);
    }

    // If all books have been returned, throw an exception letting the user know there are no more borrowed books for the selected patron
    else {
        throw runtime_error("Book not found in list of borrowed books.");
    }
};

//SECTION - Display Patron Method
// Function to display the patron's name, the patron's ID, and the list of books borrowed by the patron
void Patron::displayPatron() const {
    cout << "Name: " << name << "\nID: " << id << endl;
    cout << "Borrowed Books:" << endl;

    // Loop to display the books borrow by the patron
    for (const Book* b : borrowedBooks) {
        cout << *b << endl;
    }
};

//SECTION - Operator Overloading
//Overload the equality operator to compare two patrons based on their name and ID.
bool Patron::operator==(const Patron& other) const {
    return name == other.name && id == other.id;
};

// Overload the output operator to display the patron's information in a readable format when using cout.
ostream& operator<<(ostream& os, const Patron& p) {
    p.displayPatron();
    return os;
};