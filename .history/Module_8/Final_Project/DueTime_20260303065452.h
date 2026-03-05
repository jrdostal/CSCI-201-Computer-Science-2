//SECTION - Header guard to prevent multiple inclusions of this header file
#ifndef DUETIME_H
#define DUETIME_H

//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;
//SECTION - DueTime Class Definition
class DueTime {
    //SECTION - Data members to store the hour and minute of the due time.
    int hour;
    int minute;

    //SECTION - Public members for interface and functionality
    public:
        //Constructor for the DueTime class
        DueTime(int h, int m);
        //Method to display the due time in a readable format
        void displayTime() const;
        //Overload the output stream operator to display the time in a readable format when using cout
        friend ostream& operator<<(ostream& os, const DueTime& t);
        //Destructor for the DueTime class
        ~DueTime();
};

//SECTION - End of header guard
#endif