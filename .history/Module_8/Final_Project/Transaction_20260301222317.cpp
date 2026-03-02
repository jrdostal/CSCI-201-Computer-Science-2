#include <ctime>
#include <string>
#include "Transaction.h"
#include <iostream>

using namespace std;

class Transaction {
    int patronId;
    string bookTitle;
    string date;
    public:
        Transaction(int pid, string bt);
        void displayTransaction() const;
};

Transaction::Transaction(int pid, string bt) : patronId(pid), bookTitle(bt) {
    time_t now = time(0);
    date = ctime(&now);
};

void Transaction::displayTransaction() const {
    cout << "Patron ID: " << patronId << "\nBook Title: " << bookTitle << "\nDate: " << date << endl;
};