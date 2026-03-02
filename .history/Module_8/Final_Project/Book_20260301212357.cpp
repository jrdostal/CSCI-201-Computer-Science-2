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
        bool operator==(const Book& other) const;
        friend ostream& operator<<(ostream& os, const Book& b);
};

Book::Book(string t, string a, Genre g) : title(t), author(a), genre(g), status(BookStatus::Available) {};

Book::Book(string t, string a, Genre g) : title(t), author(a), genre(g), status(BookStatus::CheckedOut) {};

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
};

void Book::setStatus(BookStatus s) {
    status = s;
};

BookStatus Book::getStatus() const {
    return status;
};

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author && genre == other.genre;
};

ostream& operator<<(ostream& os, const Book& b) {
    b.displayInfo();
    return os;
};