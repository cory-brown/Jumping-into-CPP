/*

Jumping into C++

Chapter 14
Practice Problem

1. Write a function that builds the multiplication table of arbitrary dimensions

*/


#include <iostream>

using namespace std;

int main() {
  int x, y;

  cout << "Enter 1st dimension: ";
  cin >> x;
  cin.ignore();

  cout << "Enter 2nd dimension:";
  cin >> y;
  cin.ignore();


  int **table = new int * [x];
  for (int i =0; i < x; ++i) {
    table[i] = new int [y];
  }

  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      table[i][j] = (x * y);
      cout << table[i][j] << endl;
    }
  }

  for (int i = 0; i < x; ++i) {
    delete [] table[i];
  }
  delete [] table;

}
