#include <iostream>
using namespace std;

class InvalidMoneyValue : public exception {
   public:
      InvalidMoneyValue(string exceptionMessage) {
         message = exceptionMessage;
      }

		virtual const char* what() {
			return message.c_str();
		}

   private:
      string message;
};

int findTotalCents() {
   int numCents;

   cin >> numCents;

   if (numCents % 25 != 0) {
      throw InvalidMoneyValue("Amount cannot be converted to quarters");
   }
   return numCents;
}

int main() {
   int numCents;

   try {
      numCents = findTotalCents();

      cout << "Valid input: " << numCents << " cents = " << (numCents / 25);
		cout << " quarters" << endl;
   }
   catch (InvalidMoneyValue excpt) {
      cout << excpt.what() << endl;
   }
   catch (exception& excpt) {
      cout << "Unexpected error: " << excpt.what() << endl;
   }

   return 0;
}