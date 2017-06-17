/*

Jumping into C++

Chapter 4
Practice Problem

1. Ask the user for two users' ages, and indicate who is older; behave differently if both are over
100.

*/


#include <iostream>

using namespace std;

int main() {
  int a,b;
  cout << "Please enter the age of the first user" << endl;
  cout << "Age:"; cin >> a;
  cout << "Please enter the age of the second user" << endl;
  cout << "Age:"; cin >> b;

  if (a > b) {
    cout << "The first user is older" << endl;
  } else if (a < b) {
    cout << "The second user is older" << endl;
  } else if ((a > 100) && (b > 100)) {
    cout << "You are both over 100. WOW!" << endl;
  } else {
    cout << "You are both the same age" << endl;
  }
}
