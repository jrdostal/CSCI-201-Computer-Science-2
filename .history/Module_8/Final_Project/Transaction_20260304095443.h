#ifndef TRANSACTION_H
#define TRANSACTION_H

//SECTION - Include necessary header files
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//SECTION - Transaction Class Definition
class Transaction {
    friend class Library;
    int patronId;
    string bookTitle;
    string date;
    string transactionTime;
    public:
        Transaction(int pid, string bt, bool isReturn = false);
        void displayTransaction() const;
        ~Transaction();
};

#endif