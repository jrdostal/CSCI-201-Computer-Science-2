#include <string>
#include <iostream>

using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
      // FIXME: The following line will throw an ios_base::failure.
      //        Insert a try/catch statement to catch the exception.
      //        Clear cin's failbit to put cin in a useable state.

      //!SECTION-TRY/CATCH statment to catch ios_base::failure exception
      //SECTION - TRY statement to catch ios_base::failure exception
      try {
         //SECTION - Input age from user
         cin >> age;
      }
      
      //SECTION - CATCH statement to catch ios_base::failure exception
      catch (ios_base::failure& e) {
         // Clear input/failbit to be able to use cin again
         cin.clear();
         // Throw away the rest of the failed input line from cin buffer
         string garbage;
         getline(cin, garbage);
         // Reset age to 0 if age input is invalid
         age = 0;
      }
      //SECTION - Output name and age+1 to console
      cout << inputName << " " << (age + 1) << endl;

      //SECTION - Input name from user to continue loop
      cin >> inputName;
   }
   
   return 0;
}