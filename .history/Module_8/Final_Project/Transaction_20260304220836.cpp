//SECTION - Include necessary header files
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//SECTION - 
#include "Transaction.h"

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
    cout << "Patron ID: " << patronId << "\nBook Title: " << bookTitle << "\nDate: " << date <<  "\nTime: " << transactionTime << endl;
};

//SECTION - Destructor for the Transaction class
// The destructor for the Transaction class. Since there are no dynamically allocated resources, it can be left empty.
Transaction::~Transaction() {};