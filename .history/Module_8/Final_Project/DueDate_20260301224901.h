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
        ~DueDate();
};

DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {};

void DueDate::displayDate() const {};

ostream& operator<<(ostream& os, const DueDate& d) {};

DueDate::~DueDate() {};