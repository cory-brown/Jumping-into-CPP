// 2. Write a recursive function that takes an array and displays the elements
// in
// reverse order without starting the index of the array at the end. (In other
// words, don’t write the equivalent of a loop that starts printing at the end
// of the array.)

#include <iostream>

using namespace std;

void reverseArray(int size, int *array, int index) {

  if (index < size) {
    reverseArray(size, array, index + 1);
  }

  cout << array[index] << endl;
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14};
  int size = (sizeof(arr) / sizeof(int) - 1); // 7 - 1
  reverseArray(size, arr, 0);
}
