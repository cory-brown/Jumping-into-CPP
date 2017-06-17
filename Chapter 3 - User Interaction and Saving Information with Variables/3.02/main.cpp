/*

Jumping into C++

Chapter 3
Practice Problem

2. Write a program that reads in two numbers and adds them together.

*/


#include <iostream>

using namespace std;

int main() {
  int a,b,c;
  cout << "Please enter two number" << endl;
  cout << "Number 1:"; cin >> a;
  cout << "Number 2:"; cin >> b;
  c = a + b;
  cout << c << endl;
}
