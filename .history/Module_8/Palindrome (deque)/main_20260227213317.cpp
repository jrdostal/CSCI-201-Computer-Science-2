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

    if (pos != std::string::npos) {
        // Extract the substring before the special character using substr
        std::string result = line.substr(0, pos);
        std::cout << "String until first special character: " << result << std::endl;
    } else {
        std::cout << "No special character found, entire string is: " << line << std::endl;
    }

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
