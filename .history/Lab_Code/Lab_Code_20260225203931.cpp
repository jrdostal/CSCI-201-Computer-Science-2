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