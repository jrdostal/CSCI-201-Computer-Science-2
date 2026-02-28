#include <iostream>
#include <stdexcept>
using namespace std;

bool containsLetters(const string& input) {
    for (unsigned char c : input) {
        if (isalpha(c)) {
            return true;
        }
    }
    return false;
}

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

int main() {
    int userNum;
    int divNum;
    int result;
   cin.exceptions(ios::failbit);       // Allow cin to throw exceptions

    try {
        cin >> userNum >> divNum;

        if (divNum == 0) {
            throw DivideByZero("Divide by zero!");
        } else if (containsLetters(to_string(userNum)) || containsLetters(to_string(divNum))) {
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
