// gameMenu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {
	char input;

	cout << "Choose a value\n" << endl;
	cout << "a) Start game" << endl;
	cout << "b) Load game" << endl;
	cout << "c) New game" << endl;
	cout << "d) Exit game" << endl;

	cin >> input;

	switch (input) {
	case 'a':
		cout << "Starting game...." << endl;
		break;
	case 'b':
		cout << "Loading game...." << endl;
		break;
	case 'c':
		cout << "Starting Newgame...." << endl;
		break;
	case 'd':
		cout << "Exiting game...." << endl;
		break;
	default:
		cout << "BAD INPUT" << endl;

	}
	cin.ignore();
	cin.get();
}

