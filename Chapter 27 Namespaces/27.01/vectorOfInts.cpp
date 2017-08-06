//
// Created by Cory Brown on 04/07/2017.
//

#include "vectorOfInts.h"

namespace vector_int {

		vectorOfInt::vectorOfInt() : _size(32), _numOfElements(0) {
			_arrOfInts = new int[_size](); // Create a new array with 32 integers all initialised to 0
		};

		vectorOfInt::vectorOfInt(const int size) : _size(size), _numOfElements(0) {
			_arrOfInts = new int[_size](); // Create a new array with a user specifed size and integers all initialised to 0
		};

		vectorOfInt::vectorOfInt(const vectorOfInt &rhs) : _size(rhs._size), _numOfElements(rhs._numOfElements) {
			_arrOfInts = new int[_size]();
			for (int i = 0; i < _numOfElements; i++) {
				_arrOfInts[i] = rhs._arrOfInts[i]; // copy values
			}
		};

		vectorOfInt::~vectorOfInt() {
			delete _arrOfInts; // deletes the array
			_arrOfInts = NULL;
		};

		vectorOfInt &vectorOfInt::operator=(const vectorOfInt &rhs) {
			/*
			// 1.	 Check for self-assignment
			// 2.  Deallocate any memory that MyClass is using internally
			// 3.  Allocate some memory to hold the contents of rhs
			// 4.  Copy the values from rhs into this instance
			// 5.  Return *this
			*/
			if (this != &rhs) { // Check for self-assignment
				delete[] _arrOfInts; // Deallocate old memory


				_arrOfInts = new int[rhs._size](); // Allocate new memory

				_size = rhs._size;
				_numOfElements = rhs._numOfElements;

				for (int i = 0; i < rhs._numOfElements; i++) {
					_arrOfInts[i] = rhs._arrOfInts[i]; // copy values
				}
			}
			return *this;
		}


		int vectorOfInt::getSizeOfArray() {
			return _numOfElements;
		};

		int *vectorOfInt::resizeArray(const int startVal) {
			_size *= 2;
			int *old_array = _arrOfInts;
			int *new_array = new int[_size]();

			for (int i = startVal; i < (_numOfElements + startVal); i++) {
				new_array[i] = getValue(i - startVal);
			}

			delete[] old_array; // delete old array

			return new_array; // return new array
		};

		int vectorOfInt::getValue(const int index) {
			return _arrOfInts[index];
		};

		void vectorOfInt::setValue(const int index, int value) {
			if (_numOfElements <= _size) {
				_arrOfInts[index] = value;
			}
		};

		int &vectorOfInt::operator[](const int index) {
			return _arrOfInts[index];
		};

		void vectorOfInt::pushBack(const int value) {
			if (_numOfElements >= _size) {
				_arrOfInts = resizeArray(0);
			}
			setValue(_numOfElements, value);
			++_numOfElements;
		};

		void vectorOfInt::pushFront(const int value) {
			_arrOfInts = resizeArray(1);
			setValue(0, value);
			++_numOfElements;
		};
}
