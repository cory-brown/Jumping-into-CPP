/*
1. Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to use templates like the normal STL). Your class should have the following interface:
• A no-argument constructor that allocates a 32 element vector [Done]
• A constructor that takes an initial size as the argument [Done]
• A method get, taking an index as returning the value at that index [Done]
• A method set, that takes an index and a value, and sets the value at that index [Done]
• A method pushback that adds an element to the end of the array, resizing if necessary [Done]
• A method pushfront that adds an element to the beginning of the array [Done]
• A Copy constructor and assignment operator [Done]
Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully about how your class can be misused, and how you should handle them. What do you do if a user gives a negative initial size? What about accessing a negative index?
*/

#include "vectorOfInts.h"

using namespace vector_int;

int main () {

	vectorOfInt newArr(4);

	for (int i = 0; i < 10; i++) {
		newArr.pushBack(i);
		cout << newArr[i] << ", ";
	}; cout << endl;

	newArr.pushFront(20);
	newArr.pushFront(10);
	newArr.pushFront(50);


	for (int i = 0; i < newArr.getSizeOfArray(); i++) {
		cout << newArr[i] << ((i < newArr.getSizeOfArray() - 1) ? ", " : " ");
	}; cout << endl;



// operator overload test

	vectorOfInt anotherArr;
	anotherArr = newArr;


	cout << "Another ";
	for (int i = 0; i < anotherArr.getSizeOfArray(); i++) {
		cout << anotherArr[i] << ((i < anotherArr.getSizeOfArray() - 1) ? ", " : " ");
	}; cout << endl;



// copy constructor test

	vectorOfInt oneMoreArray(anotherArr);


	cout << "One More Array ";
	for (int i = 0; i < oneMoreArray.getSizeOfArray(); i++) {
		cout << oneMoreArray[i] << ((i < oneMoreArray.getSizeOfArray() - 1) ? ", " : " ");
	}; cout << endl;




}
