#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int guessNumber; // random number to guess
int users_input; // the users input
int counter = 0;

int randRange(int low, int high); // function to create the random number

void checkGuessNumber () {
    if (guessNumber > users_input) {
        cout << "LOWER" << endl;
        guessNumber = randRange(1, 100);
    } else if (guessNumber < users_input) {
        cout << "HIGHER" << endl;
        guessNumber = randRange(1, 100);
    }
}

int main() {
    srand( time( NULL ) );
    guessNumber = randRange(1, 100);
    cout << "Guess the Number" << endl;
    cout << "Input: ";
    cin >> users_input;
    while (guessNumber != users_input) {
        checkGuessNumber();
        cout << "Guessed number: " << guessNumber << endl;
        cout << "Count: " << ++counter << "\n" << endl;
    }
    cout << "WINNER, the number was " << guessNumber << endl;
}

int randRange(int low, int high) {
    return rand() % (high - low) + low;
}