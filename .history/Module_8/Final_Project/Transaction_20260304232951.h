#ifndef TRANSACTION_H
#define TRANSACTION_H

//SECTION - Include necessary header files
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//SECTION - Transaction Class Definition
class Transaction {
    //SECTION - Private Data Members for the Transaction class
    // Adds library as friend class to allow access to private data members
    friend class Library;

    // Data member for the patron ID
    int patronId;

    // Data member for the book title
    string bookTitle;

    // Data members for the date and time of the transaction
    string date;
    string transactionTime;

    //SECTION - Public members for interface and functionality
    public:
        // Constructor for the Transaction class
        Transaction(int pid, string bt, bool isReturn = false);

        // Function to display the transaction information
        void displayTransaction() const;

        // Destructor for the Transaction class
        ~Transaction();
};

//SECTION - End of header guard
#endif