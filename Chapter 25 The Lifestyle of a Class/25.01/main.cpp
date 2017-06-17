/*
1. Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to use templates like the normal STL). Your class should have the following interface:
• A no-argument constructor that allocates a 32 element vector [Done]
• A constructor that takes an initial size as the argument [Done]
• A method get, taking an index as returning the value at that index [Done]
• A method set, that takes an index and a value, and sets the value at that index [Done]
• A method pushback that adds an element to the end of the array, resizing if necessary
• A method pushfront that adds an element to the beginning of the array
• A Copy constructor and assignment operator
Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully about how your class can be misused, and how you should handle them. What do you do if a user gives a negative initial size? What about accessing a negative index?
*/

#include "vectorOfInt.h"

int main () {
  vectorOfInt newArr(4);
	for (int i = 0; i < newArr.getSizeOfArray(); i++) {
		newArr.pushBack(i);
		cout << newArr[i] << endl;
		cout << newArr.getSizeOfArray() << endl;
	}
}
