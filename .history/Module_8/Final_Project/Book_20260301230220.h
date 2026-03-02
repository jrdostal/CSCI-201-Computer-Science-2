#include <iostream>
#include <string>
#include <vector>

#include "DueDate.h"
#include "DueTime.h"

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
        DueDate dueDate;
        DueTime dueTime;

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