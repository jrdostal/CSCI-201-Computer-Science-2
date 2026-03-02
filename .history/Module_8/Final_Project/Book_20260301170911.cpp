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