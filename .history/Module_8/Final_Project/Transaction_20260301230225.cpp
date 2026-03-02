#include "Transaction.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Transaction::Transaction(int pid, string bt, bool isReturn) : patronId(pid), bookTitle(bt) {
    time_t now = time(0);
    date = ctime(&now);
};

void Transaction::displayTransaction() const {
    cout << "Patron ID: " << patronId << "\nBook Title: " << bookTitle << "\nDate: " << date << endl;
};