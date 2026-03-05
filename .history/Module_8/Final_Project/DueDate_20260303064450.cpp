//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "DueDate.h"

//SECTION - DueDate Constructor
DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {
    // Validate the date to ensure it is a valid calendar date. If the date is invalid, throw an exception.
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) {
        throw invalid_argument("Invalid date.");
    }
};

//SECTION - Display Date Method
//Display the date in Day/Month/Year format
void DueDate::displayDate() const {
    cout << day << "/" << month << "/" << year;
};

//SECTION - Operator Overloading
//Overload the output stream operator to display the date in a readable format when using cout.
ostream& operator<<(ostream& os, const DueDate& d) {
    d.displayDate();
    return os;

//SECTION - DueDate Destructor
// The destructor for the DueDate class. Since there are no dynamically allocated resources, it can be left empty.
DueDate::~DueDate() {};
};
