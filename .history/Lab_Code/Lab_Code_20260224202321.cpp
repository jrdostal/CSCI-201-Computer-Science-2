#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> expirationMonthVector = { 5, 8, 11, 7, 1, 6, 4, 10, 9, 2 };
   int vectorIndex;
   int expirationMonth;

   try {
      cin >> vectorIndex;
      expirationMonth = expirationMonthVector.at(vectorIndex);
      cout << "Expiration month is " << expirationMonth << " at index " << vectorIndex << endl;
   }

   catch (const out_of_range& e) {
      cout << "Error: " << e.what() << endl;
   }

   return 0;
}