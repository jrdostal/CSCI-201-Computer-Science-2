#include <iostream>
using namespace std;

int main() {
   int numEggs;
   int triesLeft = 2;

   while (triesLeft > 0) {
		cout << "Tries left: " << triesLeft << endl;

      try {
         cin >> numEggs;

         if (numEggs < 0) {
            throw invalid_argument("Invalid number of eggs");
         }

         if (numEggs % 6 != 0) {
            throw runtime_error("The number of eggs must be divisible by 6");
         }

         triesLeft = 0;
         cout << "Valid input: ";
         cout << numEggs << " eggs = " << (numEggs / 6) << " cartons of half a dozen" << endl;
      }

      /* Your code goes here */

   }
}