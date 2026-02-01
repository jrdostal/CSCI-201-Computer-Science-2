#include "memtest.h"
#include <iostream>
using namespace std;

void PrintFuchsias(int *arrayPtr, int arraySize)
{
    int i;

    if (arrayPtr != nullptr)
    {
        cout << "Fuchsias in vases: ";
        for (i = 0; i < arraySize - 1; ++i)
        {
            cout << arrayPtr[i] << ", ";
        }
        cout << arrayPtr[arraySize - 1] << endl;
    }
}

int main()
{
    int *fuchsiasReceived = nullptr;
    int numVases;
    int i;

    cin >> numVases;

    // Allocate memory for the array of fuchsias
    fuchsiasReceived = new int[numVases];
    for (i = 0; i < numVases; ++i)
    {
        cin >> fuchsiasReceived[i];
    }

    PrintFuchsias(fuchsiasReceived, numVases);

    delete[] fuchsiasReceived;

    memtest(); // Check memory for testing purposes only

    return 0;
}