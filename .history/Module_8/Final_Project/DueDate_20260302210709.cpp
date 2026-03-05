//SECTION - Include necessary header files
#include "DueDate.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - DueDate Constructor
DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) {
        throw invalid_argument("Invalid date.");
    }
};

//SECTION - Display Date Method
void DueDate::displayDate() const {
    cout << day << "/" << month << "/" << year;
};

//SECTION - Operator Overloading
ostream& operator<<(ostream& os, const DueDate& d) {
    d.displayDate();
    return os;

};
