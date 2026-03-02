#include "DueDate.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class DueDate {
    int day;
    int month;
    int year;
    public:
        DueDate(int d, int m, int y);
        void displayDate() const;
};

DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {
    if (month < 1 || month > 12) throw runtime_error("Invalid month.");
    if (day < 1 || day > 31) throw runtime_error("Invalid day.");
    // Additional checks for specific months and leap years can be added
};

void DueDate::displayDate() const {
    cout << day << "/" << month << "/" << year << endl;
};