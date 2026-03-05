//SECTION - Header guard to prevent multiple inclusions of this header file
#ifndef LIBRARY_H
#define LIBRARY_H

//SECTION - Include necessary header files
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "EBook.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

//SECTION - Library Class Definition
class Library {

    //SECTION - Containers for records used by library management system
    // Vector for book records
    vector<Book*> books;

    // Map for patron record pairs
    map<int, Patron> patrons;

    // Vector for transaction records
    vector<Transaction*> transactions;

    //SECTION - Public members for interface and functionality
    public:

        // Constructor for Library class
        Library();

        // Destructor for Library class
        ~Library();

        // Function to load data from data files for necessary records
        void loadData();

        // Function to save data to data files for necessary records
        void saveData();

        // Function to add a new book to the library inventory
        void addBook(Book* b);

        // Function to add a new patron to the library catalog
        void addPatron(const Patron& p);

        // Function to checkout a book from the library inventory
        void checkoutBook(int patronId, string title);

        // Function to return a book to the library inventory
        void returnBook(int patronId, string title);

        // Function to display all books in the library inventory
        void displayBooks() const;

        // Function to display all patrons in the library catalog
        void displayPatrons() const;

        // Function to search for books by author
        void searchByAuthor(const string& author) const;

        // Function to search for books by genre
        void searchByGenre(Genre genre) const;

        //SECTION - Template for saving data to file
        // Declares template for the function to save data to the file
        template <typename Container, typename Func>

        // Function declaration / definition for saving data  to file
        void saveToFile(const string& filename, const Container& items, Func formatter) {

            // File stream variable to handle data management
            ofstream file(filename);

            // Validates if the data file exists. If the file does exist, 
            if (!file) throw runtime_error("Failed to open " + filename + " for writing.");
            for (const auto& item : items) {
                file << formatter(item) << endl;
            }
        }
    };

#endif