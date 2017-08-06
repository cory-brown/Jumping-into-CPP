#include "newVector.hxx"

namespace zero_vector {

		template <typename Type>
		new_vector<Type>::new_vector() : _size(32), _numOfElements(0) {
			_arr = new Type[_size](); // Create a new array with 32 integers all initialised to 0
		};

		template <typename Type>
		new_vector<Type>::new_vector(const int size) : _size(size), _numOfElements(0) {
			_arr = new Type[_size](); // Create a new array with a user specifed size and integers all initialised to 0
		};

		template <typename Type>
		new_vector<Type>::new_vector(const new_vector &rhs) : _size(rhs._size), _numOfElements(rhs._numOfElements) {
			_arr = new Type[_size]();
			for (int i = 0; i < _numOfElements; i++) {
				_arr[i] = rhs._arr[i]; // copy values
			}
		};

		template <typename Type>
		new_vector<Type>::~new_vector() {
			delete[] _arr; // deletes the array
			_arr = NULL;
		};

		template <typename Type>
		new_vector<Type> &new_vector<Type>::operator=(const new_vector &rhs) {
			/*
			// 1.	 Check for self-assignment
			// 2.  Deallocate any memory that MyClass is using internally
			// 3.  Allocate some memory to hold the contents of rhs
			// 4.  Copy the values from rhs into this instance
			// 5.  Return *this
			*/
			if (this != &rhs) { // Check for self-assignment
				delete[] _arr; // Deallocate old memory


				_arr = new Type[rhs._size](); // Allocate new memory

				_size = rhs._size;
				_numOfElements = rhs._numOfElements;

				for (int i = 0; i < rhs._numOfElements; i++) {
					_arr[i] = rhs._arr[i]; // copy values
				}
			}
			return *this;
		}

		template <typename Type>
		int new_vector<Type>::getSizeOfArray() {
			return _numOfElements;
		};

		template <typename Type>
		Type *new_vector<Type>::resizeArray(const int startVal) {
			_size *= 2;
			Type *old_array = _arr;
			Type *new_array = new Type[_size]();

			for (int i = startVal; i < (_numOfElements + startVal); i++) {
				new_array[i] = getValue(i - startVal);
			}

			delete[] old_array; // delete old array

			return new_array; // return new array
		};

		template <typename Type>
		Type new_vector<Type>::getValue(const int index) {
			return _arr[index];
		};

		template <typename Type>
		void new_vector<Type>::setValue(const int index, const Type& value) {
			if (_numOfElements <= _size) {
				_arr[index] = value;
			}
		};

		template <typename Type>
		Type &new_vector<Type>::operator[](const int index) {
			return _arr[index];
		};

		template <typename Type>
		void new_vector<Type>::pushBack(const Type& value) {
			if (_numOfElements >= _size) {
				_arr = resizeArray(0);
			}
			setValue(_numOfElements, value);
			++_numOfElements;
		};

		template <typename Type>
		void new_vector<Type>::pushFront(const Type& value) {
			_arr = resizeArray(1);
			setValue(0, value);
			++_numOfElements;
		};
}
