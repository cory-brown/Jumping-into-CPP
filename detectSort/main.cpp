#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

void sort(int array[], int size);
void swap(int array[], int first_index, int second_index);
bool sorted(int array[], int size);
int findSmallestVal(int array[], int size, int index);
void print(int array[], int size);

int main() {
    srand(time(NULL)); // seed the random number
    int array[10]; // an array with 10 numbers

    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 100; // adding random numbers to each array value
    }
    print(array, 10);
    if (sorted(array, 10)) {
        cout << "List is sorted" << endl;
    } else {
        cout << "Sorting...." << endl;
        sort(array,10);
        print(array, 10);
    }
}

void sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
       int val = findSmallestVal(array, 10,i);
        swap(array, i, val);
    }
}

void swap(int array[], int first_index, int second_index){
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

bool sorted(int array[], int size) {
    int smallest_val = 0;
    bool isSorted;
for (int i = 0; i < size; i++) {
    smallest_val = findSmallestVal(array, 10, i);
}
    if (array[smallest_val] == array[0]) {
        isSorted = true;
    } else {
        cout << "List is not sorted" << endl;
        isSorted = false;
    }
    return isSorted;
}

int findSmallestVal(int array[], int size, int index) {
    int smallestVal = index;
    for(int i = index + 1; i < size; i++) {
        if(array[i] < array[smallestVal]) {
            smallestVal = i;
        }
    }
    return smallestVal;
}

void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == array[size - 1]) {
            cout << array[i] << endl;
        } else {
            cout << array[i] << ", ";
        }
    }
}