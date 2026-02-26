#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream &infoFS) {

   /* Type your code here. */
   
}

string FindName(string ID, ifstream &infoFS) {

   /* Type your code here. */
   
}

int main() {
   int userChoice;
   string studentName;
   string studentID;
   
   string studentInfoFileName;
   ifstream studentInfoFS;
   
   // Read the text file name from user
   cin >> studentInfoFileName;
   
   // Open the text file
   studentInfoFS.open(studentInfoFileName);
   
   // Read search option from user. 0: FindID(), 1: FindName()
   cin >> userChoice;

   // FIXME: FindID() and FindName() may throw an Exception.
   //        Insert a try/catch statement to catch the exception and output the exception message.
   if (userChoice == 0) {
      cin >> studentName;
      studentID = FindID(studentName, studentInfoFS);
      cout << studentID << endl;
   }
   else {
      cin >> studentID;
      studentName = FindName(studentID, studentInfoFS);
      cout << studentName << endl;
   }

   studentInfoFS.close();
   return 0;
}
