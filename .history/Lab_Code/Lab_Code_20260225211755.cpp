#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream dataFS;
   string nameOfFile;
   string line1;
   string line2;
   string line3;
   string line4;

   cin >> nameOfFile;
   cin >> line1;
   cin >> line2;
   cin >> line3;
   cin >> line4;

   /* Your code goes here */

   if (dataFS.is_open()) {  /* For testing purpose only */
      dataFS << "File is not closed." << endl;  
   }
  
   return 0;
}