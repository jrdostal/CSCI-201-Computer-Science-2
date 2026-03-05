//SECTION - Header guard to prevent multiple inclusions of this header file
#ifndef DUEDATE_H
#define DUEDATE_H

//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>

using namespace std;

//SECTION - DueDate Class Definition
class DueDate {
    //SECTION - Data members to store the day, month, and year of the due date.
    int day;
    int month;
    int year;

    //SECTION - Public members for interface and functionality
    public:

        //Constructor for the DueDate class.
        DueDate(int d, int m, int y);

        //Destructor for the DueDate class.
        ~DueDate();

        //function to display the due date in a readable format.
        void displayDate() const;
        
        //Overload the output stream operator to display the date in a readable format when using cout.
        friend ostream& operator<<(ostream& os, const DueDate& d);
};

//SECTION - End of header guard
#endif