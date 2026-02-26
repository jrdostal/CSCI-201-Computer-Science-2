#include <iostream>
using namespace std;

int main() {
   int numDancers;

   try {
      cin >> numDancers;

      if (numDancers % 2 != 0) {
         throw runtime_error("Invalid input: number of dancers must be even");
      }

      cout << "Valid input: ";
      cout << numDancers << " dancers form " << (numDancers / 2) << " pairs" << endl;
   }
   catch (runtime_error& excpt) {
      cout << excpt.what() << endl;
   }

   return 0;
}