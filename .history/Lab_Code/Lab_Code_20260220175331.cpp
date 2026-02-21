#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main () {
	// TODO: Declare a list called shoppingList of type ListItem
	list<ListItem> shoppingList;
	string item;

   // TODO: Read inputs (items) and add them to the shoppingList list
   //       Read inputs until a -1 is input
   while (true) {
      cin >> item;
      if (item == "-1") {
         break;
      }
      shoppingList.push_back(ListItem(item));
   }


   // TODO: Print the shoppingList list using the PrintNodeData() function
   for (int i = 0; i < shoppingList.size(); i++) {
      shoppingList.front().PrintNodeData();
      shoppingList.pop_front();
   }

return 0;
}