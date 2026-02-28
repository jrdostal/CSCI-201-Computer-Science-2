#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
   int userNum;
   int divNum;
   int result;
   cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

   class DivideByZero : public exception {
    public:
         DivideByZero(string exceptionMessage) {
             message = "Runtime Exception: " + exceptionMessage;
         }
 
            const char* what() const noexcept override {
                return message.c_str();
            }
 
    private:
       string message;
 };

   class InvalidInput : public exception {
    public:
         InvalidInput(string exceptionMessage) {
             message = "Input Exception: " + exceptionMessage;
         }
 
            const char* what() const noexcept override {
                return message.c_str();
            }
 
    private:
       string message;
 };

    try {
        cin >> userNum >> divNum;

        bool containsLetters(const std::string& input) {
            for (unsigned char c : input) { // Iterate through each character in the string
                if (std::isalpha(c)) {      // Check if the character is an alphabet
                    return true;            // A letter was found
                }
            }
            return false; // No letters were found in the entire string
        }

        if (divNum == 0) {
            throw DivideByZero("Divide by zero!");
        } else if (userNum == typeid(string).name() || divNum == typeid(string).name()) {
            throw InvalidInput("Invalid input! Please enter integers.");
        }
        result = userNum / divNum;
        cout << result << endl;
    }
    catch (DivideByZero& exception) {
        cout << exception.what() << endl;
    }catch (InvalidInput& excpt) {
        cout << excpt.what() << endl;
     }

   return 0;
}
