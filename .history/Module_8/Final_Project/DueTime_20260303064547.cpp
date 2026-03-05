//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "DueTime.h"

//SECTION - DueTime Constructor
DueTime::DueTime(int h, int m) : hour(h), minute(m) {
    // Validate the time to ensure it is a valid calendar time. If the time is invalid, throw an exception.
    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw invalid_argument("Invalid time.");
    }
};

//SECTION - Display Time Method
//Display the Time in Hour:Minute format.
void DueTime::displayTime() const {
    cout << hour << ":" << minute;
};

//SECTION - Operator Overloading
//Overload the << operator to display the time in Hour:Minute format.
ostream& operator<<(ostream& os, const DueTime& t) {
    os << t.hour << ":" << t.minute;
    return os;
};