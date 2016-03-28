#include <ctime>
#include <cstdlib>
#include <iostream>

// "\u2660" UTF-8 Spade
// "\u2665" UTF-8 Black Heart
// "\u2666" UTF-8 Diamond
// "\u2663" UTF-8 Club

using namespace std;

int card[4]; // 5 numbers on the cards
string suit[4]; // 5 suit on the cards
string cardValue; // returns the value of the card
int chooseSuit;

enum royaltyA {
    ACE = 1,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

int randRange(int low, int high); // generates random numbers
void assignCards();
void cards(); // displays the cards with suits
string assign(int card[], int size); //
//void changeCards(int users_input);
void suits(); // generates the suits of the card


int main() {
    srand(time(NULL)); // for the function rand() to seed the random number
    assignCards(); // run for loop <= 5
    suits();
    cards();
}

int randRange(int low, int high) {
    return rand() % (high - low) + low;
}

void cards() {
    cout << "Here are your cards" << endl;
    cout << "  ---  " << "  ---  " << "  ---  " << "  ---  " << "  ---  " << endl;
    cout << " | " << assign(card, 0) << "|  | " << assign(card, 1) << "|  | " << assign(card, 2) << "|  | " << assign(card, 3) << "|  | " << assign(card, 4) << "| " << endl;
    cout << " | " << suit[0] << " |  | " << suit[1] << " |  | " << suit[2] << " |  | " << suit[3] << " |  | " << suit[4] << " | " << endl;
    cout << "  ---  " << "  ---  " << "  ---  " << "  ---  " << "  ---  " << endl;
}

string assign(int card[], int index) {
        switch (card[index]) {
            case ACE:
                cardValue = "A ";
                break;
            case 2:
                cardValue = "2 ";
                break;
            case 3:
                cardValue = "3 ";
                break;
            case 4:
                cardValue = "4 ";
                break;
            case 5:
                cardValue = "5 ";
                break;
            case 6:
                cardValue = "6 ";
                break;
            case 7:
                cardValue = "7 ";
                break;
            case 8:
                cardValue = "8 ";
                break;
            case 9:
                cardValue = "9 ";
                break;
            case 10:
                cardValue = "10";
                break;
            case JACK:
                cardValue = "J ";
                break;
            case QUEEN:
                cardValue = "Q ";
                break;
            case KING:
                cardValue = "K ";
                break;
            default:
                cout << "Error" << endl;
                break;
        }
    return cardValue;
    }

void assignCards() {
    for(int i = 0; i < 5; i++) {
        card[i] = randRange(ACE,KING);
    }
}

void suits() {

    for (int i = 0; i < 5; i++) {
        chooseSuit = randRange(1,4);
        switch(chooseSuit) {
            case 1:
                suit[i] = "\u2660";
                break;
            case 2:
                suit[i] = "\u2665";
                break;
            case 3:
                suit[i] = "\u2666";
                break;
            case 4:
                suit[i] = "\u2663";
                break;
            default:
                cout << "Error" << endl;
                break;
        }
    }
}
/*
void changeCards(int users_input) {
    switch (users_input) {
        case 0:
            gameRunning = false;// work in progress
        case 1:
            assignCards(1);
            break;
        case 2:
            assignCards(2);
            break;
        case 3:
            assignCards(3);
            break;
        case 4:
            assignCards(4);
            break;
        case 5:
            assignCards(5);
            break;
        default:
            cout << "Error" << endl;
            break;
    }
}
 */