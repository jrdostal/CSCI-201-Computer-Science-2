#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int userNum;
   int divNum;
   int result;
   cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

    try {
        cin >> userNum >> divNum;
        if (divNum == 0) {
            throw runtime_error("Divide by zero!");
        } else if (cin.fail()) {
            throw runtime_error("basic_ios::clear: iostream error");
        }
        result = userNum / divNum;
        cout << result << endl;
    }
    catch (runtime_error& e) {
        cout << "Runtime Exception: " << e.what() << endl;
    }catch (runtime_error& e) {
        cout << "Input Exception: " << e.what() << endl;
    }

   return 0;
}
