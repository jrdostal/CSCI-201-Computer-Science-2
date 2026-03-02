#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Genre { Fiction, NonFiction, Mystery, Science, Biography };
enum class BookStatus { Available, CheckedOut };

class Book {
    protected:
        string title;
        string author;
        Genre genre;
        BookStatus status;

    public:
        Book(string t, string a, Genre g);
        virtual ~Book() = default;
        virtual void displayInfo() const;
        void setStatus(BookStatus s);
        BookStatus getStatus() const;
        string getTitle() const { return title; };
        string getAuthor() const { return author; };
        Genre getGenre() const { return genre; };
        bool operator==(const Book& other) const;
        friend ostream& operator<<(ostream& os, const Book& b);
        friend class Library;
        friend class Patron;
        friend class Transaction;
        friend class PrintedBook;
        friend class EBook;
};