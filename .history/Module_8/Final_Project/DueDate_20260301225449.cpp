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
        friend ostream& operator<<(ostream& os, const DueDate& d);
        ~DueDate() = default;
};

DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) {
        throw invalid_argument("Invalid date.");
    }
};

DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {
    d = 1; m = 1; y = 2024;
};

void DueDate::displayDate() const {
    cout << day << "/" << month << "/" << year;
};

ostream& operator<<(ostream& os, const DueDate& d) {
    d.displayDate();
    return os;

};
