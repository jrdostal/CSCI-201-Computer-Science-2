   #include <iostream>
   using namespace std;
   
   class InvalidBirthMonth : public exception {
      public:
         InvalidBirthMonth(string exceptionMessage) {
            message = "Error: " + exceptionMessage;
         }
         virtual const char* what() {
            return message.c_str();
         }
      private:
         string message;
   };
   
   int findBirthMonth() {
      int birthMonth;
   
      cin >> birthMonth;
   
      if ((birthMonth < 1) || (birthMonth > 12)) {
         throw InvalidBirthMonth("Input cannot be processed");
      }
      return birthMonth;
   }
   
   int main() {
      int birthMonth;
   
      try {
         birthMonth = findBirthMonth();
   
         cout << "Valid input: Birth month is " ;
         cout << birthMonth << endl;
      }
      catch (InvalidBirthMonth excpt) {
         cout << excpt.what() << endl;
      }
      catch (exception& excpt) {
         cout << "Unexpected error: " << excpt.what() << endl;
      }
   
      return 0;
   }