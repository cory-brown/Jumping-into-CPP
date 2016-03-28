// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int add(int x, int y) {
	return x + y;
}
int subtract(int x, int y) {
	return x - y;
}
int divide(int x, int y) {
	return x / y;
}
int multiply(int x, int y) {
	return x * y;
}

void menuItems(int number, string item)
{
	cout << number << ")" << item << endl;
}
void bottleRhyme() {
	for (int i = 99; i >= 0; i--) {

		if (i == 0) {
			cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
		}
		else {
			cout << i << " bottles of beer on the wall, " << i << " bottles of beer. Take one down, pass it around " << endl;
		}
	}
}
void calculatorProgram() {

	string usedOperator;
	int number_1 = 0;
	int number_2 = 0;
	int z = 1;
	while (z == 1) {
		cout << "Please enter the operator that you want to use or enter 0 to quit\n" << endl;
		cin >> usedOperator;
		cout << "Enter first number" << endl;
		cin >> number_1;
		cout << "Enter second number" << endl;
		cin >> number_2;

		if (usedOperator == "+") {
			cout << "Result: " << add(number_1, number_2) << endl;
		}
		else if (usedOperator == "-") {
			cout << "Result: " << subtract(number_1, number_2) << endl;
		}
		else if (usedOperator == "/") {
			cout << "Result: " << divide(number_1, number_2) << endl;
		}
		else if (usedOperator == "*") {
			cout << "Result: " << multiply(number_1, number_2) << endl;
		}
		else {
			if (usedOperator == "0") {
				z = 0;
			}
		}
	}
}
void checkLogin(string checkUsername, string checkPassword) {

	string username1 = "bob";    // User
	string password1 = "45";     // 1

	string username2 = "jack";	// User
	string password2 = "21";	// 2

	string username3 = "john";	// User
	string password3 = "96";	// 3

	if (username1 == checkUsername && password1 == checkPassword ||
		username2 == checkUsername && password2 == checkPassword ||
		username3 == checkUsername && password3 == checkPassword) {
		cout << "Access Grained" << endl;
	}
	else {
		cout << "try again One more attempt" << endl << endl;
		checkUsername;
		checkPassword;
		cout << " Please enter your username" << endl;
		cin >> checkUsername;
		cout << " Please enter your password" << endl;
		cin >> checkPassword;

		if (username1 == checkUsername && password1 == checkPassword ||
			username2 == checkUsername && password2 == checkPassword ||
			username3 == checkUsername && password3 == checkPassword) {
			cout << "Access Grained" << endl;
		}
		else {
			cout << "Access Deined" << endl;
		}
	}
}

void tweleveDaysOfChristmas(int day) {
	switch (day) {
	case 12:
		cout << "Tweleve Drummers Drumming" << endl;
	case 11:
		cout << "Eleven Pipers Piping" << endl;
	case 10:
		cout << "Ten Lords are Leaping" << endl;
	case 9:
		cout << "Nine Ladies Dancing" << endl;
	case 8:
		cout << "Eight Maids are  Milking" << endl;
	case 7:
		cout << "Seven Swans are Swimming" << endl;
	case 6:
		cout << "Six Geese are Laying" << endl;
	case 5:
		cout << "Five Gold Rings" << endl;
	case 4:
		cout << "Four Calling Birds" << endl;
	case 3:
		cout << "Three French Hens" << endl;
	case 2:
		cout << "Two Turtle Doves" << endl;
	case 1:
		if (day >=2) {
			cout << "and a Partridge in a Pear Tree." << endl;
		}
		else {
			cout << "a Partridge in a Pear Tree." << endl;
		}
		
	}
}

int main() {
	/*
	string inputedUsername;
	string inputedPassword;

	cout << " Please enter your username" << endl;
	cin >> inputedUsername;
	cout << " Please enter your password" << endl;
	cin >> inputedPassword;
	checkLogin(inputedUsername, inputedPassword);
	*/
	// Password program

	/*

	int option = 0;

	string bottles = "99 Bottle of Beer";
	string calculator = "Calculator";

	cout << "Please choose one of the options below :" << endl;
	menuItems(1, bottles);
	menuItems(2, calculator);
	menuItems(3, "Bike");

	cin >> option;

	switch (option) {
	case 1:
		bottleRhyme();
		break;
	case 2:
		calculatorProgram();
		break;
	default:
		for (option; option > 3;) {
			cout << "Please choose one of the options below :" << endl;
			menuItems(1, bottles);
			menuItems(2, calculator);
			menuItems(3, "Bike");

			cin >> option;
		}

		cout << "You Picked " << option << endl;
		break;
	}
	*/
	// Menu program 

	/*
	int input = 1;

	cout << "Enter a number" << endl;

	while(!input == 0) {
		cin >> input;
		input += input;
		cout << input << endl;
	}
	*/
	// Running sum program

	/*
	int attempts = 3;
	string password = "pass";
	string inputedPassword;

	cout << "Enter your password" << endl;
	cout << "Password: ";
	cin >> inputedPassword;
	for (attempts; attempts >= 0; attempts--) {

		if (password == inputedPassword) {
			cout << "Welcome" << endl;
			break;
		}
		else {
			cout << "try again. \n" << "you have " << attempts << " attempts left" << endl;
			cout << "Password: ";
			cin >> inputedPassword;
		}
	}
	*/
	// Password Prompt

	/*
	for (int i = 1; i <= 20; i++) {

	cout << i << "*" << i << "=" << i*i << endl;

	}

	*/
	// First 20 squared numbers 

	/*
	int inputedAnswer = 0;

	int answer_1 = 0;
	int answer_2 = 0;
	int answer_3 = 0;

	for (int i = 1; i <= 3; i++) {

		cout << "POLL \n" << endl;
		cout << "How many hours do you spend on the internet a day?" << endl;
		cout << "1) 1" << endl;
		cout << "2) 3" << endl;
		cout << "3) 5+" << endl;
		cin >> inputedAnswer;
		cout << "" << endl;

		switch (inputedAnswer) {
		case 1:
			answer_1++;
			break;
		case 2:
			answer_2++;
			break;
		case 3:
			answer_3++;
			break;
		default:
			cout << "Invalid Entry" << endl;
			break;
		}
	}
	cout << "Results\n" << endl;
	cout << " Answer 1: ";
	for (int i = 0; i < answer_1; i++) { //Answer 1
		cout << "*";
	}
	cout << "\n Answer 2: ";
	for (int i = 0; i < answer_2; i++) { //Answer 2
		cout << "*";
	}
	cout << "\n Answer 3: ";
	for (int i = 0; i < answer_3; i++) { //Answer 3
		cout << "*";
	}
	*/
	// Poll 

	/*
	int verse = 1;
	string day;
	for (verse; verse <= 12; verse++) {
		switch (verse) {
		case 12:
			day = "Twelfth";
			break;
		case 11:
			day = "Eleventh";
			break;
		case 10:
			day = "Tenth";
			break;
		case 9:
			day = "Ninth";
			break;
		case 8:
			day = "Eighth";
			break;
		case 7:
			day = "Seventh";
			break;
		case 6:
			day = "Sixth";
			break;
		case 5:
			day = "Fifth";
			break;
		case 4:
			day = "Fourth";
			break;
		case 3:
			day = "Third";
			break;
		case 2:
			day = "Second";
			break;
		case 1:
			day = "First";
			break;
		}
		if (verse == 1) {
			cout << "On the " << day << " day of Christmas my true love sent to me" << endl;
		}
		else {
			cout << "\nOn the " << day << " day of Christmas my true love sent to me" << endl;
		}
		tweleveDaysOfChristmas(verse);
	}
	*/
	// 12 days of Christmas

	cin.ignore();
	cin.get();
}