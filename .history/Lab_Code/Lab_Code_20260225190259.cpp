#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
   string fileName;
   ifstream weightInStream;
   double valueRead;

   cin >> fileName;
   
   weightInStream.exceptions(ifstream::failbit);

   try {
      weightInStream.open(fileName);

      weightInStream >> valueRead;
      cout << "Value read from " << fileName << ": " << valueRead << endl;
   }
   catch (ios_base::failure& excpt) {
      cout << "Error occurred: " << excpt.what() << endl;
   }

   // Closes the opened file
   if (weightInStream.is_open()) {
      weightInStream.close();
   }

   return 0;
}