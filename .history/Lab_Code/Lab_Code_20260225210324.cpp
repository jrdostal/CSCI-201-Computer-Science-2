#include <iostream>
#include <iomanip>
using namespace std;

class DataOutOfRange : public exception {
   public:
      DataOutOfRange(string exceptionMessage) {
         message = "Error: " + exceptionMessage;
      }
      virtual const char* what() {
         return message.c_str();
      }
   private:
      string message;
};

double getPyramidWidth() {
   double pyramidWidth;

   cin >> pyramidWidth;

   if (pyramidWidth < 0.0) {

      throw DataOutOfRange("Pyramid's width cannot be negative.");

   }
   return pyramidWidth;
}

int main() {
   double pyramidWidth;

   try {
      pyramidWidth = getPyramidWidth();

      cout << "Valid input: Pyramid's width (in cm) is " << fixed << setprecision(1);
		cout << pyramidWidth << endl;
   }
   catch (DataOutOfRange excpt) {
      cout << excpt.what() << endl;
   }
   catch (exception& excpt) {
      cout << "Unexpected error: " << excpt.what() << endl;
   }

   return 0;
}