#include <iostream>
using namespace std;

int main() {
   int numEggs;

   try {
      cin >> numEggs;

		if (numEggs <= 0) {
			throw invalid_argument("Positive value expected");
		}

		if (numEggs % 6 != 0) {
			throw runtime_error("The number of eggs must be divisible by 6");
		}

		cout << "Valid input: ";
		cout << numEggs << " eggs = " << (numEggs / 6) << " cartons of half a dozen" << endl;
   }

   catch (const invalid_argument& e) {
      cerr << "Error: Positive value expected" << e.what() << endl;
   }
   catch (const runtime_error& e) {
      cerr << "Runtime error: " << e.what() << endl;
   }


   return 0;
}