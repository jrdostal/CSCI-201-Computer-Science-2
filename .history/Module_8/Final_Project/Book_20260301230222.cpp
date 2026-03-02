#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"

using namespace std;

Book::Book(string t, string a, Genre g, BookType bt) : title(t), author(a), genre(g), type(bt), status(BookStatus::Available), dueDate(1, 1, 2024), dueTime(12, 0) {};

void Book::displayInfo() const {
    cout << "Title: " << title << "\nAuthor: " << author << "\nGenre: ";
    switch (genre) {
        case Genre::Fiction: cout << "Fiction"; break;
        case Genre::NonFiction: cout << "Non-Fiction"; break;
        case Genre::Mystery: cout << "Mystery"; break;
        case Genre::Science: cout << "Science"; break;
        case Genre::Biography: cout << "Biography"; break;
    }
    cout << "\nStatus: " << (status == BookStatus::Available ? "Available" : "Checked Out") << endl;

    if (status == BookStatus::CheckedOut) {
        cout << "Due Date: " << dueDate << "\nDue Time: " << dueTime << endl;
    }
    cout << endl;
};

void Book::setStatus(BookStatus s) {
    status = s;
};

BookStatus Book::getStatus() const {
    return status;
};

string Book::getTitle() const {
    return title;
};

string Book::getAuthor() const {
    return author;
};

Genre Book::getGenre() const {
    return genre;
};

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author && genre == other.genre;
};

ostream& operator<<(ostream& os, const Book& b) {
    b.displayInfo();
    return os;
};