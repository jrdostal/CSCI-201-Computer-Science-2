#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream guavaFS;
   string nameOfFile;
   double guavaQuantity;

   cin >> nameOfFile;
   cin >> guavaQuantity;

   //String nameOfFile and double guavaQuantity are read from input. Open nameOfFile as an output file. If the file fails to open:
   //Use cout to output nameOfFile followed by ": file-open operation failure" and a newline.
   //Terminate the program with 1 as the return value without writing to the file.

   guavaFS.open(nameOfFile);
   if (!guavaFS) {
      cout << nameOfFile << ": file-open operation failure" << endl;
      return 1;
   }


   guavaFS.close();
   
   return 0;
}