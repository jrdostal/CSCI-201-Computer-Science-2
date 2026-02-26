#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream cradleFS;
   int cradleQuantity;

   /* Your code goes here */

   if (!cradleFS.is_open()) {
      cout << "data3.txt: could not be opened" << endl;
      return 1;
   }

   cradleFS >> cradleQuantity;

   cout << cradleQuantity << endl;

   cradleFS.close();

   return 0;
}