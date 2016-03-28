#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int findSmallestRemainingElement (int array[], int index, int size); // finds the smallest element
void swap (int array[], int first_index, int second_index); // swaps the values around
void sort (int array[], int size); // sorts the values
void displayArray (int array[], int size); // displays the array
void insertionSort(int array[], int size); // Combines all function to create a more dynamic program

int main() {
    int array[ 10 ];
    srand( time( NULL ) );
    insertionSort(array, 10);
}

void sort (int array[], int size)
{
    for ( int i = 0; i < size; i++ )
    {
        int index = findSmallestRemainingElement( array, size, i );
        swap( array, i, index );
    }
}
int findSmallestRemainingElement (int array[], int size, int index)
{
    int index_of_smallest_value = index;
    for (int i = index + 1; i < size; i++)
    {
        if ( array[ i ] < array[ index_of_smallest_value ] )
        {
            index_of_smallest_value = i;
        }
    }
    return index_of_smallest_value;
}
void swap (int array[], int first_index, int second_index)
{
    int temp = array[ first_index ];
    array[ first_index ] = array[ second_index ];
    array[ second_index ] = temp;
}
// small helper method to display the before and after arrays
void displayArray (int array[], int size)
{
    cout << "{";
    for ( int i = 0; i < size; i++ )
    {
// you'll see this pattern a lot for nicely formatting
// lists--check if we're past the first element, and
// if so, append a comma
        if ( i != 0 )
        {
            cout << ", ";
        }
        cout << array[ i ];
    }
    cout << "}";
}

void insertionSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
// keep the numbers small so they're easy to read
        array[ i ] = rand() % 100;
    }
    cout << "Original array: ";
    displayArray( array, size );
    cout << '\n';
    sort( array, size );
    cout << "Sorted array: ";
    displayArray( array, size );
    cout << '\n';
}