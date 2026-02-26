#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> monthOfBirthVector = { 3, 6, 2, 11, 5, 1, 10, 7, 8, 4, 9 };
   int requestIndex;
   int monthOfBirth;
   bool needInput = true;

   while (needInput) {

      /* Begin your try block here */
      try{

         cin >> requestIndex;
         monthOfBirth = monthOfBirthVector.at(requestIndex);
         needInput = false;
      }
      /* End your try block here */

   /* Your catch block goes here */
      catch (const out_of_range& e) {
         cout << "Invalid index. Please enter a number between 0 and " << monthOfBirthVector.size() - 1 << "." << endl;
      }

   }

   cout << "Month of birth is " << monthOfBirth << " at index " << requestIndex << endl;

   return 0;
}