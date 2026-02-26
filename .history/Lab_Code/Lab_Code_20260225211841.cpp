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

   /* Variables nameOfFile, line1, line2, line3, and line4, are read from input. Perform the following tasks:

   Open nameOfFile as the output file.
   If the output file fails to open, then use cout to output nameOfFile followed by ": error occurred while opening file" and a newline. Then, terminate the program with 1 as the return value.
   Otherwise, for strings line1, line2, line3, and line4, write "ZIP code: " followed by the string and a newline to the output file.
   Close the file.
*/

   dataFS.open(nameOfFile);
   if (!dataFS.is_open()) {
      cout << nameOfFile << ": error occurred while opening file" << endl;
      return 1;
   }
   dataFS << "ZIP code: " << line1 << endl;
   dataFS << "ZIP code: " << line2 << endl;
   dataFS << "ZIP code: " << line3 << endl;
   dataFS << "ZIP code: " << line4 << endl;
   dataFS.close();


   if (dataFS.is_open()) {  /* For testing purpose only */
      dataFS << "File is not closed." << endl;  
   }
  
   return 0;
}