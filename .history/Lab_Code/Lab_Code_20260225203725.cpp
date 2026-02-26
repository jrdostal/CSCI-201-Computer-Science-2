#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
   string volumeDataName;
   ifstream dataStream;
   double inValue;

   cin >> volumeDataName;
   dataStream.exceptions(ifstream::failbit);

   try {
      dataStream.open(volumeDataName);

      dataStream >> inValue;
      cout << "Value read from " << volumeDataName << ": " << inValue << endl;
   }
	catch (ios_base::failure& excpt) {

      cerr << "Unexpected event: " << excpt.what() << endl;

	}

   // Closes the opened file
   if (dataStream.is_open()) {
      dataStream.close();
   }

   return 0;
}