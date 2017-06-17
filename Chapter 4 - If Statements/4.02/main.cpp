/*

Jumping into C++

Chapter 4
Practice Problem

2. Implement a simple "password" system that takes a password in the form of a number. Make it
so that either of two numbers are valid, but use only one if statement to do the check.

*/


#include <iostream>

using namespace std;

int main() {
  int inputedPassword;
  int password = 500;
  cout << "Please enter your password. (Must be in the form of a number)" << endl;
  cin >> inputedPassword;
  if (inputedPassword == password) {
    cout << "Access Grained" << endl;
  } else {
    cout << "Access Denied" << endl;
  }
}
