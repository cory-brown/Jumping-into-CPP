#include <iostream>

using namespace std;


int findElement(int* array, int element, int size, int index){
  if (element == array[index]) {
    return array[index];
  } else if ((index > size) || (array[index] > element)) {
    return -1;
  } else {
    return findElement(array, element, size, index+1);
  }
}

int main() {

  const int sizeOfArray = 5;
  int sortedArray[sizeOfArray] = {1, 2, 3, 4, 5};

  cout << findElement(sortedArray, 2, sizeOfArray, 0) << endl;

}
