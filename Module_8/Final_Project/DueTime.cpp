#include "DueTime.h"
#include <iostream>
#include <stdexcept>

using namespace std;

DueTime::DueTime(int h, int m) : hour(h), minute(m) {
    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw invalid_argument("Invalid time.");
    }
};

void DueTime::displayTime() const {
    cout << hour << ":" << minute;
};

ostream& operator<<(ostream& os, const DueTime& t) {
    os << t.hour << ":" << t.minute;
    return os;
};