#include <fstream>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

void add_student(const string &roster) {
   try {
      ofstream output_file(roster, ios::app);
      if (!output_file) {
         throw ios_base::failure("basic_ios::clear: iostream error");
      }
      output_file << "Smith,John,24,12345678" << endl;
      output_file.close();
   } catch (const ios_base::failure &e) {
      cout << "Permission Error: " << e.what() << endl;
   }
   
}

int main() {
   string roster;
   cout << "Enter the roster filename: ";
   cin >> roster;
   add_student(roster);

   return 0;
}
