/*

Jumping into C++

Chapter 4
Practice Problem

3. Write a small calculator that takes as input one of the four arithmetic operations, the two
arguments to those operations, and then prints out the result

*/

#include <iostream>

using namespace std;

int main() {
	string usedOperator;
	int number_1 = 0;
	int number_2 = 0;
	int z = 1;
	cout << "Please enter the operator that you want to use or enter 0 to quit" << endl;
	cin >> usedOperator;
	if (usedOperator == "0") {
	  z = 0;
	  return z;
	}
	cout << "Enter first number" << endl;
	cin >> number_1;
	cout << "Enter second number" << endl;
	cin >> number_2;

	if (usedOperator == "+") {
		cout << "Result: " << number_1 + number_2 << endl;
	}
	else if (usedOperator == "-") {
		cout << "Result: " << number_1 - number_2 << endl;
	}
	else if (usedOperator == "/") {
		cout << "Result: " << number_1 / number_2 << endl;
	}
	else if (usedOperator == "*") {
		cout << "Result: " << number_1 * number_2 << endl;
	}
	else {
	  cout << "Error. Please try again." << endl;
	}
}
