//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "DueTime.h"

//SECTION - DueTime Constructor
DueTime::DueTime(int h, int m) : hour(h), minute(m) {
    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw invalid_argument("Invalid time.");
    }
};

//SECTION - Display Time Method
void DueTime::displayTime() const {
    cout << hour << ":" << minute;
};

//SECTION - Operator Overloading
ostream& operator<<(ostream& os, const DueTime& t) {
    os << t.hour << ":" << t.minute;
    return os;
};