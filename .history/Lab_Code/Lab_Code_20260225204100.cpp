#include "testcode.h"  // For testing purposes
#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
   string volumeDataName;
   ofstream dataOutStream;
   double inValue;

   cin >> volumeDataName;
   cin >> inValue;

   // throw an exception if the file cannot be opened for writing or the file does not exist
try {      dataOutStream.exceptions(ios::failbit | ios::badbit);
   }
   catch (ios_base::failure& excpt) {
      cout << "Error setting exceptions: " << excpt.what() << endl;
      return 1; // Exit with an error code
   }

   try {
      dataOutStream.open(volumeDataName, ios::app); // Opens the file for writing

      dataOutStream << inValue;
   }
   catch (ios_base::failure& excpt) {
      cout << "Error with file: " << excpt.what() << endl;
   }

   // Closes the opened file
   if (dataOutStream.is_open()) {
      dataOutStream.close();
   }

   RunTests();  // For testing purposes

   return 0;
}