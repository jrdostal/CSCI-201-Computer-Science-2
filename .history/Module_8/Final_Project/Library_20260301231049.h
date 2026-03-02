#ifndef LIBRARY_H
#define LIBRARY_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
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
    };

#endif