#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

string heads = "Heads";
string tails = "Tails";
string user_input;
int i;

enum Coin {
    HEADS = 1, TAILS = 2
};

int randRange(int high, int low) {
    return rand() % (high - low) + low;
}

int rand();

int main() {
    srand(time(NULL));
    i = 1;
    while (i == 1) {
        cout << "Type flip to begin\n " << endl;
        cin >> user_input;
        randRange(3, 1);
        if (randRange(3, 1) == HEADS) {
            cout << "\n" << heads << endl;
        } else if (randRange(3, 1) == TAILS) {
            cout << "\n" << tails << endl;
        }
    }
}
