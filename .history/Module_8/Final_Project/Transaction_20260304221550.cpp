//SECTION - Include necessary header files
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Transaction.h"

//SECTION - Transaction Constructor
// Constructor for the Transaction class
Transaction::Transaction(int pid, string bt, bool isReturn) : patronId(pid), bookTitle(bt) {

    // Get current date and time
    time_t now = time(0);
    date = ctime(&now);

    // Validate if the transaction is a return or a checkout. Adds the type of transaction to the date/time.
    if (isReturn) {
        date += " (Return)";
    } else {
        date += " (Checkout)";
    }

    //Removes trailing newline
    date.pop_back();
};

//SECTION - Display Transaction function
// Function to display the transaction information
void Transaction::displayTransaction() const {
    // Display the patron ID, book title, date, and time of the transaction
    cout << "Patron ID: " << patronId << "\nBook Title: " << bookTitle << "\nDate: " << date <<  "\nTime: " << transactionTime << endl;
};

//SECTION - Destructor for the Transaction class
// The destructor for the Transaction class. Since there are no dynamically allocated resources, it can be left empty.
Transaction::~Transaction() {};