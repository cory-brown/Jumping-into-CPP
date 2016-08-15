#include <iostream>

using namespace std;


void buildTable(int *** p_p_pMultiTable, int length, int width, int height);
void popTable(int *** p_p_pMultiTable, int length, int width, int height);
void printTable(int *** p_p_pMultiTable, int length, int width, int height);
void deleteTable(int *** p_p_pMultiTable, int length, int width);

// Write a function that takes 3 arguments, a length, width and height,
// dynamically allocates a 3dimensional array with those values and fills
// the 3-dimensional array with multiplication tables.
// Make sure to free the array when you are done.

int main() {
    int length = 12, // how many tables
        width = 12, // how many columns
        height = 12; // how many rows

    int *** p_p_pMultiTable = new int **[length];
    buildTable(p_p_pMultiTable, length,  width, height);
    popTable(p_p_pMultiTable, length, width, height);
    printTable(p_p_pMultiTable, length, width, height);
    deleteTable(p_p_pMultiTable, length, width);

}

void buildTable(int *** p_p_pMultiTable, int length, int width, int height) {
    for (int i = 0; i < length; ++i) {
        p_p_pMultiTable[i] = new int * [width];
        for (int j = 0; j < width; ++j) {
            p_p_pMultiTable[i][j] = new int [height];
        }
    }
}

void popTable (int *** p_p_pMultiTable, int length, int width, int height) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < height; ++k) {
                p_p_pMultiTable[i][j][k] = (i + 1) * (j + 1) * (k + 1); // the '+ 1' is because the for loop starts at 0
            }
        }
    }
}

void printTable(int *** p_p_pMultiTable, int length, int width, int height) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < height; ++k) {
                cout << p_p_pMultiTable[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void deleteTable(int *** p_p_pMultiTable, int length, int width) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            delete [] p_p_pMultiTable[i][j]; // deallocate the values in the array
        }
        delete [] p_p_pMultiTable [i]; //deallocate the rows in the array
    }
    delete [] p_p_pMultiTable; // deallocate the columns in the array
}