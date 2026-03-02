#include "DueTime.h"
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
        ~DueTime() = default;
};

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