#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int highestNumber(int array[], int size); // finds the highest number in the array
int lowestNumber(int array[], int size);// finds the lowest number in the array
int averageNumber(int array[], int size);// finds average number in the array

int main() {
    srand(time(NULL));
    int array[10]; // an array with 50 values

    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100; // generates random number and adds it into the array
        cout << array[i] << ", "; // prints the values in the array and adds a comma to the end
    } // for loop
    cout << " \nHighest Value = " << highestNumber(array, 10) << endl;
    cout << " Lowest Value = " << lowestNumber(array, 10) << endl;
    cout << " Average Value = " << averageNumber(array,10) << endl;

}// main()

int highestNumber(int array[], int size){
    int firstValue = 0;
    for (int i = firstValue + 1; i < size; i++) {
        if(array[i] > array[firstValue]) {
            firstValue = i;
        }
    }
    return array[firstValue];
}
int lowestNumber(int array[], int size) {
    int firstValue = 0;
    for (int i = firstValue + 1; i < size; i++) {
        if(array[i] < array[firstValue]) {
            firstValue = i;
        }
    }
    return array[firstValue];
}
int averageNumber(int array[], int size) {
    int lowest = lowestNumber(array, size);
    int highest = highestNumber(array, size);

    return highest - lowest;
};