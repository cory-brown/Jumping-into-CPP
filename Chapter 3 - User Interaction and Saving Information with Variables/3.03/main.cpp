/*

Jumping into C++

Chapter 3
Practice Problem

3. Write a program that performs division of two numbers read from the user and prints out an
exact result. Make sure to test your program with both integer inputs and decimal inputs.

*/


#include <iostream>

using namespace std;

int main() {
  int a,b;
  cout << "Please enter two number" << endl;
  cout << "Number 1:"; cin >> a;
  cout << "Number 2:"; cin >> b;
  cout << a / b << endl;
}
