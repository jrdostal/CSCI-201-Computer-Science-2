#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Print the integers in vector nums separated by a space
void PrintNums(vector<int> nums, int size) {
   for (int i = 0; i < size; ++i) {
      cout << nums.at(i) << " ";
   }
}

// Used in uniqueRandomInt, printed in main()
int retries;

// Generate howMany unique random integers 0 <= N < maxNum and return in nums
vector<int> UniqueRandomInts(unsigned int howMany, int maxNum) {
   int nextRand;
   retries = 0;
   set<int> alreadySeen;
   vector<int> nums;

   /* Type your code here. */

}

int main() {
   unsigned int howMany;
   unsigned int maxNum;

   cin >> howMany;
   cin >> maxNum;
   vector<int> uniqueInts;

   srand(641);                      // Seed random number generator for testing

   uniqueInts = UniqueRandomInts(howMany, maxNum);
   PrintNums(uniqueInts, howMany);
   cout << "  [" << retries << " retries]" << endl;
   
   return 0;
}
