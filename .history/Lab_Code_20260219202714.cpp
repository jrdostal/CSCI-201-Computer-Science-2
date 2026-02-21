#include <string>
#include <iostream>

using namespace std;

// TODO: Define a generic method called CheckOrder() that
//       takes in four variables of generic type as arguments.
//       The return type of the method is integer

int CheckOrder(auto arg1, auto arg2, auto arg3, auto arg4) {
   if (arg1 < arg2 && arg2 < arg3 && arg3 < arg4) {
      return -1; // ascending
   } else if (arg1 > arg2 && arg2 > arg3 && arg3 > arg4) {
      return 1; // descending
   } else {
      return 0; // neither
   }
}

// Check the order of the input: return -1 for ascending,
// 0 for neither, 1 for descending



int main() {
   // Read in four strings
   string stringArg1, stringArg2, stringArg3, stringArg4;
   cin >> stringArg1;
   cin >> stringArg2;
   cin >> stringArg3;
   cin >> stringArg4;
   // Check order of four strings
   cout << "Order: " << CheckOrder(stringArg1, stringArg2, stringArg3, stringArg4) << endl;

   // Read in four doubles
   double doubleArg1, doubleArg2, doubleArg3, doubleArg4;
   cin >> doubleArg1;
   cin >> doubleArg2;
   cin >> doubleArg3;
   cin >> doubleArg4;
   // Check order of four doubles
   cout << "Order: " << CheckOrder(doubleArg1, doubleArg2, doubleArg3, doubleArg4) << endl;
   
   return 0;
}