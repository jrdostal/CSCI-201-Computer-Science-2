//SECTION - Include necessary header files
#include "Transaction.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//SECTION - Transaction Constructor
Transaction::Transaction(int pid, string bt, bool isReturn) : patronId(pid), bookTitle(bt) {
    time_t now = time(0);
    date = ctime(&now);
    if (isReturn) {
        date += " (Return)";
    } else {
        date += " (Checkout)";
    }
    date.pop_back(); // remove trailing newline
};

//SECTION - Display Transaction Method
void Transaction::displayTransaction() const {
    cout << "Patron ID: " << patronId << "\nBook Title: " << bookTitle << "\nDate: " << date << endl;
};