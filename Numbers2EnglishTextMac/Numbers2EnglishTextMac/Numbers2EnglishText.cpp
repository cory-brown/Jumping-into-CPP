// Numbers2EnglishText.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

// 1 one
// 10 ten
// 100 one hundred 

// 1000 one thousand
// 10,000 ten thousand
// 100,000 one hundred thousand

// 1,000,000 one million
// 10,000,000 ten million
// 100,000,00 one hundred million

string translateUnits(int unit) {
	switch (unit) {
        case 1:
            cout << "one";
            break;
        case 2:
            cout << "two";
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        case 6:
            cout << "six";
            break;
        case 7:
            cout << "seven";
            break;
        case 8:
            cout << "eight";
            break;
        case 9:
            cout << "nine";
            break;
        default:
            break;
	}
    return 0;
}



int main() {
	int number = 0;
	cout << "Please enter a number too be translated into Text" << endl;
	cin >> number;
    translateUnits(number);
    cout << number <<endl;

}

