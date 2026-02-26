#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream deskFS;
   string fileName;
   int deskQuantity;
	int totalQuantity;

   cin >> fileName;

   deskFS.open(fileName);
   if (!deskFS.is_open()) {
      cout << fileName << ": program exiting due to file error" << endl;
      return 1;
   }

	totalQuantity = 0;

	cout << "Started with: " << totalQuantity << endl;
   
   deskFS >> deskQuantity;

while (!deskFS.fail()) {
   cout << deskQuantity << endl;
	totalQuantity = totalQuantity + deskQuantity;
   deskFS >> deskQuantity;
}

   if (deskFS.eof()) {
      cout << "Reached end of file" << endl;
   }
   else {
      cout << "Read operation failed" << endl;
   }

	cout << "Sum: " << totalQuantity << endl;

   deskFS.close();

   return 0;
}