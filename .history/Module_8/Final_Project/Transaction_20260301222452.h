#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Transaction {
    int patronId;
    string bookTitle;
    string date;
    public:
        Transaction(int pid, string bt);
        void displayTransaction() const;
};