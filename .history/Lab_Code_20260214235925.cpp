#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   int seedVal;
   int limitValue;
	int data1;
	int data2;
	int data3;
   int sum;

   cin >> seedVal;
   cin >> limitValue;

   srand(seedVal);

    data1 = rand() % limitValue;
    data2 = rand() % limitValue;
    data3 = rand() % limitValue;

	sum = data1 + data2 + data3;

	cout << data1 << endl;
	cout << data2 << endl;
	cout << data3 << endl;
	cout << "Sum: " << sum << endl;

   return 0;
}