#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream dataFS;
   double melonCount;
   string friendName;

   cin >> melonCount;
   cin >> friendName;
  
   dataFS.open("note.txt");
   if (!dataFS.is_open()) {
      cout << "note.txt" << ": failed to open file" << endl;
      return 1;
   }

   /* Your code goes here */

   dataFS.close();
   
   return 0;
}