#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   int seedVal;
	int numFaces;
	int rollValue1;
	int rollValue2;
	int rollValue3;
	int rollValue4;

   cin >> seedVal;
	cin >> numFaces;

   srand(seedVal);

    rollValue1 = rand() % numFaces + 1;
    rollValue2 = rand() % numFaces + 1;
    rollValue3 = rand() % numFaces + 1;
    rollValue4 = rand() % numFaces + 1;

	cout << rollValue1 << endl;
	cout << rollValue2 << endl;
	cout << rollValue3 << endl;
	cout << rollValue4 << endl;

   return 0;
}