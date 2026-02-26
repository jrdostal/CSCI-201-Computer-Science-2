#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> poleHeightVector = { 35, 39, 45, 32, 28, 25, 34, 36, 44, 40, 37 };
   int vIndex;
   int poleHeight;

   /* Begin your try block here */
   try {

      cin >> vIndex;
      poleHeight = poleHeightVector.at(vIndex);
      cout << "Pole's height (in cm): " << poleHeight << " at index " << vIndex << endl;
   }
   /* End your try block here */

   catch (out_of_range& excpt) {
      cout << "Error: Invalid index for poleHeightVector" << endl;
   }

   return 0;
}