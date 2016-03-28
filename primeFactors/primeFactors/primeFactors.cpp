// primeFactors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isDivisible(int number, int divisor);
bool isPrime(int number);
bool isFactor(int number);

int main() {
	int prime = 0;
	bool quit = true;
	while(quit) {
		cout << "Enter a Prime Number " << endl;
		cin >> prime;
		if (prime == 0) {
			quit = false;
		} else if (isPrime(prime)){
			cout << prime << " this is a prime number" << endl;
		} else {
			cout << prime << " is not a prime number" << endl;
		}
	}
}

bool isPrime(int number) {
	for (int i = 2; i < number; i++) {  
		if (isDivisible(number, i)) { 
			return false; 
		}  
	} 
	return true;
}

bool isDivisible(int number, int divisor) {
	return number % divisor == 0;
}

/*
bool isFactor(int number) {

}
*/