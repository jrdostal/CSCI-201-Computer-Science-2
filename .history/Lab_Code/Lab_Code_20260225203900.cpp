#include "testcode.h"  // For testing purposes
#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
   string fileName;
   ifstream chiveStream;
   int dataValue;

   cin >> fileName;
   chiveStream.exceptions(ifstream::failbit);

   try {
      chiveStream.open(fileName);

      chiveStream >> dataValue;
      cout << "Value read from " << fileName << ": " << dataValue << endl;
   }
   catch (ios_base::failure& excpt) {
      cout << "Something went wrong: " << excpt.what() << endl;
   }

	if (chiveStream.is_open()) {
		chiveStream.close();
	}

   RunTests(chiveStream);  // For testing purposes

   return 0;
}