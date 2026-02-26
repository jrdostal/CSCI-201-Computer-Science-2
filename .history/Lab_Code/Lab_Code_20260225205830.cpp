#include "testcode.h"  // For testing purposes
#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
   string figDataName;
   ofstream figStream;
   int figValue;

   cin >> figDataName;
   cin >> figValue;

   

   try {
      figStream.open(figDataName, ios::app); // Opens the file for writing

      figStream << figValue;
   }
   catch (ios_base::failure& excpt) {
      cout << "Error occurred: " << excpt.what() << endl;
   }

   // Closes the opened file
   if (figStream.is_open()) {
      figStream.close();
   }

   RunTests();  // For testing purposes

   return 0;
}