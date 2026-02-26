#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream &infoFS) {

   string line;
   string ID;
   
   while (getline(infoFS, line)) {
      int spacePos = line.find(' ');
      string currentName = line.substr(0, spacePos);
      string currentID = line.substr(spacePos + 1);
      
      if (currentName == name) {
         return currentID;
      }
   }
   
   throw runtime_error("Student ID not found for " + name);
}

string FindName(string ID, ifstream &infoFS) {

   string line;
   string name;
   
   while (getline(infoFS, line)) {
      int spacePos = line.find(' ');
      string currentName = line.substr(0, spacePos);
      string currentID = line.substr(spacePos + 1);
      
      if (currentID == ID) {
         return currentName;
      }
   }
   
   throw runtime_error("Student name not found for " + ID);
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

   if (userChoice == 0) {
      cin >> studentName;
      try {
         studentID = FindID(studentName, studentInfoFS);
         cout << studentID << endl;
      } catch (const runtime_error& e) {
         cout << e.what() << endl;
      }
   }
   else {
      cin >> studentID;
      try {
         studentName = FindName(studentID, studentInfoFS);
         cout << studentName << endl;
      } catch (const runtime_error& e) {
         cout << e.what() << endl;
      }
   }

   studentInfoFS.close();
   return 0;
}
