//SECTION - Include necessary header files
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"

//SECTION - Book Constructor
// The constructor initializes the book's title, author, genre, type, and sets the initial status to Available. It also initializes the due date and time to default values (1/1/2024 at 12:00).
Book::Book(string t, string a, Genre g, BookType bt, int p) : title(t), author(a), genre(g), type(bt), status(BookStatus::Available), (p), dueDate(1, 1, 2024), dueTime(12, 0) {};

//SECTION - Display Information function
// This function displays the book's information, including title, author, genre, and status. If the book is checked out, it also displays the due date and time.
void Book::displayInfo() const {
    // Display book information: title, author, genre, and status. If the book is checked out, also display due date and time.
    cout << "Title: " << title << "\nAuthor: " << author << "\nGenre: ";
    //Switch statement to convert Genre enum to string for display purposes.
    switch (genre) {
        case Genre::Fiction: cout << "Fiction"; break;
        case Genre::NonFiction: cout << "Non-Fiction"; break;
        case Genre::Mystery: cout << "Mystery"; break;
        case Genre::Science: cout << "Science"; break;
        case Genre::Biography: cout << "Biography"; break;
    }
    cout << "\nStatus: " << (status == BookStatus::Available ? "Available" : "Checked Out") << endl;

    // If the book is checked out, display the due date and time.
    if (status == BookStatus::CheckedOut) {
        cout << "Due Date: " << dueDate << "\nDue Time: " << dueTime << endl;
    }
    cout << endl;
};

//SECTION - Setters and Getters
//Function to set the status of the book (Available or CheckedOut).
void Book::setStatus(BookStatus s) {
    status = s;
};

//Function to return the current status of the book.
BookStatus Book::getStatus() const {
    return status;
};

//Function to return the title of the book.
string Book::getTitle() const {
    return title;
};

//Function to return the author of the book.
string Book::getAuthor() const {
    return author;
};

//Function to return the genre of the book.
Genre Book::getGenre() const {
    return genre;
};

//SECTION - Operator Overloading
//Overload the equality operator to compare two books based on their title, author, and genre.
bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author && genre == other.genre;
};

//Overload the output stream operator to display book information when using cout.
ostream& operator<<(ostream& os, const Book& b) {
    b.displayInfo();
    return os;
};

//SECTION - Book Destructor
// The destructor for the Book class. Since there are no dynamically allocated resources, it can be left empty.
Book::~Book() {};