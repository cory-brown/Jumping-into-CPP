#ifndef INC_29_02_NEWVECTOR_H
#define INC_29_02_NEWVECTOR_H


#include <iostream>

using namespace std;

namespace zero_vector {

		template <typename Type> class new_vector {
		private:
				Type *_arr;
				int _size;
				int _numOfElements;
		public:
				new_vector(); // Will allocate 32 elements NOTE: the parentherses are used to initialise all of the values in the array with 0
				new_vector(const int size);  // Will set a user defined size of elements in the array
				new_vector(const new_vector &rhs); // Copy constructor - Need this when, you initialise a newly created object with another array
				~new_vector(); // - Deconstructor - clear all memory and prevent memory leaks
				Type &operator[](const int index); // this gets rid of the setter and getter methods
				new_vector &operator=(const new_vector &rhs); // Assignment operator
				int getSizeOfArray(); // Returns the size of the container
				Type *resizeArray(const int startVal); // Resizes the array when it runs out of space
				Type getValue(const int index); // Returns the a value at given index
				void setValue(const int index, const Type& value); // Sets a value at the given index
				void pushBack(const Type& value); // adds a value at the end of the array
				void pushFront(const Type& value); // adds a value at the beginning of the array
		};
}

#endif //INC_29_02_NEWVECTOR_H
