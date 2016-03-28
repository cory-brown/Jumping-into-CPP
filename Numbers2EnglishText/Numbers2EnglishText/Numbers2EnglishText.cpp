// Numbers2EnglishText.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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


// DONE!!!! :)

void translateUnits(int unit) {
	 if (unit == 1) {
		cout << "one";
	}
	else if (unit == 2) {
		cout << "two";
	}
	else if (unit == 3) {
		cout << "three";
	}
	else if (unit == 4) {
		cout << "four";
	}
	else if (unit == 5) {
		cout << "five";
	}
	else if (unit == 6) {
		cout << "six";
	}
	else if (unit == 7) {
		cout << "seven";
	}
	else if (unit == 8) {
		cout << "eight";
	}
	else if (unit == 9) {
		cout << "nine";
	}
	else if (unit == 10) {
		cout << "ten";
	}
	else if (unit == 11) {
		cout << "eleven";
	}
	else if (unit == 12) {
		cout << "twelve";
	}
	else if (unit == 13) {
		cout << "thirteen";
	}
	else if (unit == 14) {
		cout << "fourteen";
	}
	else if (unit == 15) {
		cout << "fifteen";
	}
	else if (unit == 16) {
		cout << "sixteen";
	}
	else if (unit == 17) {
		cout << "seventeen";
	}
	else if (unit == 18) {
		cout << "eighteen";
	}
	else if (unit == 19) {
		cout << "nineteen";
	}
}

void translateTens(int tens) {
	int unit = (tens % 10);

	if (tens >= 20 && tens < 30) {
		cout << "twenty ";
		translateUnits(unit);
	}
	else if (tens >= 30 && tens < 40) {
		cout << "thirty ";
		translateUnits(unit);
	}
	else if (tens >= 40 && tens < 50) {
		cout << "fourty ";
		translateUnits(unit);
	}
	else if (tens >= 50 && tens < 60) {
		cout << "fifty ";
		translateUnits(unit);
	}
	else if (tens >= 60 && tens < 70) {
		cout << "sixty ";
		translateUnits(unit);
	}
	else if (tens >= 70 && tens < 80) {
		cout << "seventy ";
		translateUnits(unit);
	}
	else if (tens >= 80 && tens < 90) {
		cout << "eighty ";
		translateUnits(unit);
	}
	else if (tens >= 90 && tens < 100) {
		cout << "ninety ";
		translateUnits(unit);
	}
}

void translateHundo(int hun) {
	int unit = (hun / 100);
	int ten = (hun % 100);

	if (hun >= 100) {
		translateUnits(unit);
		cout << " hundred ";
		if (ten > 19) {
			translateTens(ten);
		}
		else {
			translateUnits(ten);
		}
	}
	else {
		if (hun > 19) {
			translateTens(hun);
		}
		else {
			translateUnits(hun);
		}
	}
}

void translateThou(int thou) {
	int first = (thou / 1000);
	int last = (thou % 1000);

	if (thou >= 1000 && thou < 1000000) {
		if (thou < 20000) {
			translateUnits(first);
		}
		else if (thou >= 20000 && thou < 100000) {
			translateTens(first);
		}
		else {
			translateHundo(first);
		}
		cout << " thousand ";
		translateHundo(last);
	}
}

void translateMill(int mill) {
	int first = (mill / 1000000);
	int last = (mill % 1000000);

	if (mill >= 1000000 && mill < 1000000000) {
		if (mill < 20000000) {
			translateUnits(first);
		}
		else if (mill >= 20000000 && mill < 100000000) {
			translateTens(first);
		}
		else {
			translateHundo(first);
		}
		cout << " million ";
		translateThou(last);
	}
}

int main() {
	int number = 0;
	int i = 1;
	while (i == 1) {
		cout << "\nPlease enter a number too be translated into Text" << endl;
		cin >> number;

		if (number == 0) {
			i = 0;
		}
		else if (number < 19) {
			translateUnits(number);
		}
		else if (number >= 20 && number < 100) {
			translateTens(number);
		}
		else if (number >= 100 && number < 1000) {
			translateHundo(number);
		}
		else if (number >= 1000 && number < 1000000) {
			translateThou(number);
		}
		else if(number >= 1000000 && number < 10000000000) {
			translateMill(number);
		}
	}
}

