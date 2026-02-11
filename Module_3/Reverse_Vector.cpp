// standard library includes
#include <iostream>
#include <vector>

// namespace declaration
using namespace std;

// main function
int main()
{
    // A vector to hold the user's input integers
    vector<int> userInts;

    // Variable to store user input
    int input;

    // output prompt
    cout << "Enter integers (type -1 to stop): " << endl;

    // Prompt the user for input
    cin >> input;

    // Loop to read integers until -1 is entered
    while (input != -1)
    {
        // Check if the input is -1 to stop
        if (input == -1)
        {
            // Exit the loop if the user inputs -1
            break;
        }
        // Store the integer in the vector
        userInts.push_back(input);

        // Read the next integer from the user
        cin >> input;
    }

    // Output the integers entered by the user
    cout << "You entered: ";

    // Loop through the vector to display the integers in order they were originally entered
    for (int i = 0; i < userInts.size(); i++)
    {
        // Output each integer followed by a space
        cout << userInts[i] << " ";
    }
    // New line for better output formatting
    cout << endl;

    // Output the integers in reverse order
    cout << "The integers in reverse order are: ";

    // Loop through the vector to display the integers in reverse order
    for (int i = (userInts.size() - 1); i >= 0; i--)
    {
        // Output each integer followed by a space
        cout << userInts[i] << " ";
    }

    // New line for better output formatting
    cout << endl;

    // end program
    return 0;
}
