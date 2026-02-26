#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> colorIntensityVector = { 94, 28, 12, 121, 4, 152, 241, 81, 151 };
   int vecIndex;
   int colorIntensity;
   bool validIndex = false;

   while (!validIndex) {

      try{
         cout << "Enter an index to access the color intensity vector: ";
         cin >> vecIndex;

         if (vecIndex < 0 || vecIndex >= colorIntensityVector.size()) {
            throw out_of_range("Index is out of range");
         }

         colorIntensity = colorIntensityVector.at(vecIndex);
         validIndex = true;
      }

      catch (out_of_range& excpt) {
         cout << "Error: Index does not exist for colorIntensityVector" << endl;
      }
   }

   cout << "Color intensity: " << colorIntensity << " at index " << vecIndex << endl;

   return 0;
}