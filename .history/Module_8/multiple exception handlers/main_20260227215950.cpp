#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int userNum;
   int divNum;
   int result;
   cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

   class InvalidInput : public exception {
    public:
         InvalidInput(string exceptionMessage) {
             message = "Error: " + exceptionMessage;
         }
 
            const char* what() const noexcept override {
                return message.c_str();
            }
 
    private:
       string message;
 };

    try {
        cin >> userNum >> divNum;
        if (divNum == 0) {
            throw InvalidInput("Divide by zero!");
        }
        result = userNum / divNum;
        cout << result << endl;
    }
    catch (runtime_error& e) {
        cout << "Runtime Exception: " << e.what() << endl;
    }catch (InvalidInput excpt) {
        cout << excpt.what() << endl;
     }

   return 0;
}
