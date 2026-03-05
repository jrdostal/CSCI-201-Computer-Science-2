#ifndef DUETIME_H
#define DUETIME_H

//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - DueTime Class Definition
class DueTime {
    int hour;
    int minute;
    public:
        DueTime(int h, int m);
        void displayTime() const;
        friend ostream& operator<<(ostream& os, const DueTime& t);
        ~DueTime();
};

//SECTION - Inline Implementations (if any)
DueTime::DueTime(int h, int m) : hour(h), minute(m) {};

void DueTime::displayTime() const {};

ostream& operator<<(ostream& os, const DueTime& t) {};

DueTime::~DueTime() {};

#endif