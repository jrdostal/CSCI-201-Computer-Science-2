#ifndef LIBRARY_H
#define LIBRARY_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Book.h"
#include "EBook.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

using namespace std;

class Library {
    vector<Book*> books;
    vector<Patron> patrons;
    vector<Transaction*> transactions;
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
        void searchByAuthor(const string& author) const;
        void searchByGenre(Genre genre) const;

        template <typename T, typename Func>
        void saveToFile(const string& filename, const vector<T>& items, Func formatter) {
            ofstream file(filename);
            if (!file) throw runtime_error("Failed to open " + filename + " for writing.");
            for (const auto& item : items) {
                file << formatter(item) << endl;
            }
        }
    };

#endif