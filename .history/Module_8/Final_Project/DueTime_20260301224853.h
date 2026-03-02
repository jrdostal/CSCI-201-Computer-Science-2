#include <iostream>
#include <stdexcept>

using namespace std;

class DueTime {
    int hour;
    int minute;
    public:
        DueTime(int h, int m);
        void displayTime() const;
        friend ostream& operator<<(ostream& os, const DueTime& t);
        ~DueTime();
};

DueTime::DueTime(int h, int m) : hour(h), minute(m) {};

void DueTime::displayTime() const {};

ostream& operator<<(ostream& os, const DueTime& t) {};

DueTime::~DueTime() {};