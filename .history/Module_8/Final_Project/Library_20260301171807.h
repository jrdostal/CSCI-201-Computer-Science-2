#include "Book.h"
#include "Patron.h"
#include "Transaction.h"
#include <vector>


class Library {
    vector<Book*> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
    public:
        ~Library();
        void loadData();
        void saveData();
        void addBook(Book* b);
        void addPatron(const Patron& p);
        void checkoutBook(int patronId, string title);
        void returnBook(int patronId, string title);
        void displayBooks() const;
        void displayPatrons() const;
    };