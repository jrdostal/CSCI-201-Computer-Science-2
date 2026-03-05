//SECTION - Header guard to prevent multiple inclusions of this header file
#ifndef BOOK_H
#define BOOK_H

//SECTION - Include necessary header files
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "DueDate.h"
#include "DueTime.h"

//SECTION - Enumerations for Book properties

//Genre enumeration to categorize books into different genres.
enum class Genre { Fiction, NonFiction, Mystery, Science, Biography };

//BookStatus enumeration to indicate whether a book is available or checked out.
enum class BookStatus { Available, CheckedOut };

//BookType enumeration to differentiate between printed books and eBooks.
enum class BookType { Printed, EBook };

//SECTION - Book Class Definition
class Book {
    //SECTION - Protected members to allow access in derived classes
    protected:

        //Title of the book.
        string title;
        //Author of the book.
        string author;
        //Genre of the book, using the Genre enumeration.
        Genre genre;
        //Status of the book, using the BookStatus enumeration.
        BookStatus status;
        //Type of the book, using the BookType enumeration.
        BookType type;
        //Due date for when the book is checked out.
        DueDate dueDate;
        //Due time for when the book is checked out.
        DueTime dueTime;

    //SECTION - Public members for interface and functionality
    public:
        //Constructor for the Book class.
        Book(string t, string a, Genre g, BookType bt);
        //Destructor for the Book class.
        virtual ~Book() = default;
        //Virtual method to display book information, can be overridden by derived classes.
        virtual void displayInfo() const;
        //Setter for the status of the book (Available or CheckedOut).
        void setStatus(BookStatus s);
        //Getter for the current status of the book.
        BookStatus getStatus() const;
        //Getter for the title of the book.
        string getTitle() const { return title; };
        //Getter for the author of the book.
        string getAuthor() const { return author; };
        //Getter for the genre of the book.
        Genre getGenre() const { return genre; };
        //Getter for the due date of the book.
        DueDate getDueDate() const { return dueDate; };
        //Getter for the due time of the book.
        DueTime getDueTime() const { return dueTime; };
        //Overloaded equality operator to compare two books based on their title, author, and genre.
        bool operator==(const Book& other) const;
        //Overloaded output stream operator to display book information when using cout.
        friend ostream& operator<<(ostream& os, const Book& b);
        //Friend classes that can access private and protected members of Book.
        friend class Library;
        friend class Patron;
        friend class Transaction;
        friend class PrintedBook;
        friend class EBook;
};

//SECTION - End of header guard
#endif