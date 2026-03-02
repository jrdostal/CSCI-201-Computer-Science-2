#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"

using namespace std;

enum class Genre { Fiction, NonFiction, Mystery, Science, Biography };
enum class BookStatus { Available, CheckedOut };
enum class BookType { Printed, EBook };

class Book {
    protected:
        string title;
        string author;
        Genre genre;
        BookStatus status;
        BookType type;
        DueDate dueDate; // Assuming DueDate is a class defined elsewhere
        DueTime dueTime; // Assuming DueTime is a class defined elsewhere

    public:
        Book(string t, string a, Genre g, BookType bt);
        virtual ~Book() = default;
        virtual void displayInfo() const;
        void setStatus(BookStatus s);
        BookStatus getStatus() const;
        string getTitle() const { return title; };
        string getAuthor() const { return author; };
        Genre getGenre() const { return genre; };
        DueDate getDueDate() const { return dueDate; };
        DueTime getDueTime() const { return dueTime; };
        bool operator==(const Book& other) const;
        friend ostream& operator<<(ostream& os, const Book& b);
        friend class Library;
        friend class Patron;
        friend class Transaction;
        friend class PrintedBook;
        friend class EBook;
};

Book::Book(string t, string a, Genre g, BookType bt) : title(t), author(a), genre(g), type(bt), status(BookStatus::Available) {};

Book::Book(string t, string a, Genre g, BookType bt) : title(t), author(a), genre(g), type(bt), status(BookStatus::CheckedOut) {};


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