// standard library includes
#include <iostream>
#include <vector>

// namespace declaration
using namespace std;

// main function
int main()
{
    // Read integers into a vector until -1 is encountered
    // Then, for each integer in the vector, output the product of that integer and the last integer in the vector

    // variable for vector
    vector<int> intVect;

    // variable for input
    int value;

    // variable for loop iteration
    int i;

    // gather initial input from user
    cin >> value;

    // loop to store values in vector until -1 is encountered
    while (value != -1)
    {
        // store value in vector
        intVect.push_back(value);

        // gather next input from user
        cin >> value;
    }

    // variable to store product
    int product = 1;

    // variable to store last value in vector
    int lastValue = intVect[intVect.size() - 1];

    // loop to calculate and output product of each value in vector and last value
    for (i = 0; i < intVect.size(); i++)
    {
        // calculate product
        product = intVect[i] * lastValue;

        // output product
        cout << product << endl;
    }

    // end program
    return 0;
}