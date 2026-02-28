#include <iostream>
#include <deque>

using namespace std;

int main() {
   string line;
   bool result;
   string special_chars = ":;!@#$%^&*()";

   getline(cin, line);
   deque<char> d;

    size_t pos = line.find_first_of(special_chars);

   for (char c : line) {
      if (isalpha(c)) {
         d.push_back(tolower(c));
      }
   }
   result = true;
   while (d.size() > 1) {
      if (d.front() != d.back()) {
         result = false;
         break;
      }
      d.pop_front();
      d.pop_back();
   }
   
   if (result) {
      cout << "Yes, \"" << line << "\" is a palindrome." << endl;
   } else {
      cout << "No, \"" << line << "\" is not a palindrome." << endl;
   }
   
   return 0;
}
