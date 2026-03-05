//SECTION - Header guard to prevent multiple inclusions of this header file
#ifndef DUEDATE_H
#define DUEDATE_H

//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - DueDate Class Definition
class DueDate {
    int day;
    int month;
    int year;
    public:
        DueDate(int d, int m, int y);
        void displayDate() const;
        friend ostream& operator<<(ostream& os, const DueDate& d);
        ~DueDate();
};

//SECTION - Inline Implementations (if any)
DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {};

DueDate::~DueDate() {};

void DueDate::displayDate() const {};

ostream& operator<<(ostream& os, const DueDate& d) {};

#endif