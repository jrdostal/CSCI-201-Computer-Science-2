#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream chestFS;
   string dataFileName;
   int chestCount;

   cin >> dataFileName; // Assigns dataFileName with a string read from input
   
   chestFS.open(dataFileName); // Attempts to open the file associated with dataFileName

   if (!chestFS.is_open()) { // Checks if the file was successfully opened
      cout << dataFileName << ": open operation failed"  << endl;
      return 1; // Exits with an error code
   }

   chestFS >> chestCount;

   cout << chestCount << endl;

   chestFS.close();

   return 0;
}