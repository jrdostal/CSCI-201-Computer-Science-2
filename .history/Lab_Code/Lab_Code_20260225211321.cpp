#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream inFS;
   string fileName;
   string purchaserName;
   int tableQuantity;

   cin >> fileName;

   inFS.open(fileName);
   if (!inFS.is_open()) {
      cout << fileName << ": program exiting due to error" << endl;
      return 1;
   }

   while (!inFS.eof()) {
      inFS >> purchaserName >> tableQuantity;

      if (!inFS.fail()) {
         cout << purchaserName << " purchased " << tableQuantity << " tables." << endl;
      }
   }

   inFS.close();

   return 0;
}