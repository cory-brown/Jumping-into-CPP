//
// Created by Cory Brown on 04/07/2017.
//

#ifndef INC_27_01_VECTOROFINTS_H
#define INC_27_01_VECTOROFINTS_H

#include <iostream>

using namespace std;

namespace vector_int {

		class vectorOfInt {
		private:
				int *_arrOfInts;
				int _size;
				int _numOfElements;
		public:
				vectorOfInt(); // Will allocate 32 elements NOTE: the parentherses are used to initialise all of the values in the array with 0
				vectorOfInt(const int size);  // Will set a user defined size of elements in the array
				vectorOfInt(
								const vectorOfInt &rhs); // Copy constructor - Need this when, you initialise a newly created object with another array
				~vectorOfInt(); // - Deconstructor - clear all memory and prevent memory leaks
				int &operator[](const int index); // this gets rid of the setter and getter methods
				vectorOfInt &operator=(const vectorOfInt &rhs); // Assignment operator
				int getSizeOfArray(); // Returns the size of the container
				int *resizeArray(const int startVal); // Resizes the array when it runs out of space
				int getValue(const int index); // Returns the a value at given index
				void setValue(const int index, int value); // Sets a value at the given index
				void pushBack(const int value); // adds a value at the end of the array
				void pushFront(const int value); // adds a value at the beginning of the array
		};
}


#endif //INC_27_01_VECTOROFINTS_H
