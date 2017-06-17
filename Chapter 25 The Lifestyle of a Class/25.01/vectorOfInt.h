#ifndef INC_25_01_VECTOROFINT_H
#define INC_25_01_VECTOROFINT_H


#include <iostream>

using namespace std;

class vectorOfInt {
private:
  int* _arrOfInts;
  int _size;
  int _numOfElements;
public:
  vectorOfInt(); // Will allocate 32 elements NOTE: the parentherses are used to initialise all of the values in the array with 0
  vectorOfInt(const int size);  // Will set a user defined size of elements in the array
  vectorOfInt(const vectorOfInt& rhs); // Copy constructor - Need this when, you initialise a newly created object with another array
  ~vectorOfInt(); // - Deconstructor - clear all memory and prevent memory leaks
	int& operator[](const int index); // this gets rid of the setter and getter methods
	vectorOfInt& operator=(const vectorOfInt& rhs); // Assignment operator
	int getSizeOfArray();
	int* resizeArray();
  int getValue(const int index);
  void setValue(const int index, int value);
  void pushBack(const int value);
  void pushFront(const int value);
};

#endif //INC_25_01_VECTOROFINT_H
