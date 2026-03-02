#include "DueDate.h"
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
};