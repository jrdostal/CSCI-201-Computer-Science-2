#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   int seedVal;
	int value1;
	int value2;
	int value3;
	int value4;
   int sum;

   cin >> seedVal;

   srand(seedVal);

    value1 = rand() % 28;
    value2 = rand() % 28;
    value3 = rand() % 28;
    value4 = rand() % 28;

	sum = value1 + value2 + value3 + value4;

	cout << value1 << endl;
	cout << value2 << endl;
	cout << value3 << endl;
	cout << value4 << endl;
	cout << "Sum: " << sum << endl;

   return 0;
}