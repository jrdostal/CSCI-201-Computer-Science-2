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
   //Click here for examples

   //Ex 1: If the input is volume2.txt 3.6, then volume2.txt contains: 3.6
   
   //Ex 2: If the input is /unavailable/nosuchfile.txt 51, then the output is:
   
   //Error with file: basic_ios::clear: iostream error
   
   
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