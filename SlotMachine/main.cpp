#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int S1;
int S2;
int S3;

void slots();
int randRange(int low, int high);
void checkResults();
int money = 0;

int main() {
    srand(time(NULL));
    while (true) {
        S1 = randRange(1, 7);
        S2 = randRange(1, 7);
        S3 = randRange(1, 7);
        slots();
        checkResults();
        cout << "Money Left: £" << money << endl;
        cin.ignore();
        cin.get();
    }
}

void slots() {
    cout << "Press Enter twice to spin" << endl;
    cout << "-------------" << endl;
    cout << "| $JACKPOT$ | O" << endl;
    cout << "------------- |" << endl;
    cout << "| " << S1 << " | " << S2 <<" | " << S3 << " | |" << endl;
    cout << "------------- -" << endl;
    cout << "|   |   |   |" << endl;
    cout << "-------------" << endl;
}

void checkResults() {
    if (S1 == S2 && S1 == S3) { // if all numbers are equal
        cout << "JACKPOT" << endl;
        money += 5;
    } else if (S1 == S2 || S1 == S3 || S3 == S2 || S3 == S1) {
        cout << "Winner" << endl;
        ++money;
    } else {
        cout << "Try Again" << endl;
        --money;
    }
}

int randRange(int low, int high) {
    return rand() % (high - low) + low;
}