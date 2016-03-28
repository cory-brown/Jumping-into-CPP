#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int guessNumber; // random number to guess
int users_input; // the users input

int randRange(int low, int high); // function to create the random number

void checkGuessNumber () {
    cout << "Guess the Number" << endl;
    cout << "Input: ";
    cin >> users_input;
    if (users_input > guessNumber) {
        cout << "LOWER" << endl;
    } else if (users_input == guessNumber) {
        cout << "WINNER, the number was " << guessNumber + 1 << " just kidding it was " << guessNumber << endl;
    } else if (users_input < guessNumber) {
        cout << "HIGHER" << endl;
    }
}

int main() {
    srand( time( NULL ) );
    guessNumber = randRange(1, 100);
    while (users_input != guessNumber) {
        checkGuessNumber();
    }
}

int randRange(int low, int high) {
    return rand() % (high - low) + low;
}