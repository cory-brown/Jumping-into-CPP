#include "vectorOfInt.h"

vectorOfInt::vectorOfInt () : _size(32), _numOfElements(0) {
	_arrOfInts = new int[_size]();
};

vectorOfInt::vectorOfInt(const int size) : _size(size), _numOfElements(0) {
	_arrOfInts = new int[_size]();
};

vectorOfInt::~vectorOfInt() {
	delete[] _arrOfInts;
	_arrOfInts = NULL;
};

/*

vectorOfInt(const vectorOfInt& rhs); // this can be completed when i have figured out how to create the assignment operator method

vectorOfInt& vectorOfInt::operator=(const vectorOfInt& rhs) {
	if (this != &rhs) {

	}
	return *this;
}
*/



int vectorOfInt::getSizeOfArray() {
	return _size;
};

int* vectorOfInt::resizeArray() {
	_size *= 2;
	int* new_array = new int [_size];
	for (int i = 0; i < _size; i++) {
		new_array[i] = getValue(i);
	}

	delete _arrOfInts; // delete old array and return new array

	return new_array;
};

int vectorOfInt::getValue(const int index) {
	return _arrOfInts[index];
};

void vectorOfInt::setValue(const int index, int value) {
	_arrOfInts[index] = value;
};

int& vectorOfInt::operator[](const int index) {
	return _arrOfInts[index];
};

void vectorOfInt::pushBack(const int value) {
  _arrOfInts[_numOfElements++] = value;
	if (_numOfElements == _size) {
		_arrOfInts = resizeArray();
	}
};

//void vectorOfInt::pushFront(const int value) {};
