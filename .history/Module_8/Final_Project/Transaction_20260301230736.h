#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Transaction {
    int patronId;
    string bookTitle;
    string date;
    public:
        Transaction(int pid, string bt, bool isReturn = false);
        void displayTransaction() const;
};