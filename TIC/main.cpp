// TicTacToe.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

char POSITION_1 = '1';
char POSITION_2 = '2';
char POSITION_3 = '3';
char POSITION_4 = '4';
char POSITION_5 = '5';
char POSITION_6 = '6';
char POSITION_7 = '7';
char POSITION_8 = '8';
char POSITION_9 = '9';
// Positions on the TTT Board
// TTT Means TICTACTOE !!!

enum TicTacToe {
	X = 1,O = 2
};
// The players constant
TicTacToe player = X;
char playersChar; // holds the players character
bool gameRunning = true;

void TicTacToeBoard();
// function prototype - Prints out the TICTACTOE board
void PLAYER (int player_input, char playerChar);
// function prototype -
bool winningPositions(char PLAYER);

void choosePlayers();

int main() {

	int PLAYER_input; // player1's input

	string players_input;

	cout << "Player One is X, which is represented by 1" << endl;
	cout << "Player Two is O, which is represented by 2" << endl;
	cout << "Player one, Please pick a position to start \n" << endl;
    // Game Begins
    while(gameRunning) {
        TicTacToeBoard(); // Display the TTT board
        choosePlayers(); // Choose the player
        PLAYER(PLAYER_input, playersChar); // takes the players input and replaces the position the TTT board
        if (winningPositions(playersChar)) {
            if (playersChar == 'X') {
                cout << "Player 1 has won" << endl;
                cout << "Do you want to play another game?" << endl;
                cout << "Yes or No " << endl;
                cin >> players_input;
                if (players_input == "yes" || "YES" || "Yes") {
                    return gameRunning;
                } else {
                    return !gameRunning;
                }
            } else {
                cout << "Player 2 has won" << endl;
            }
            return !gameRunning;
        } // checks to see if the player has won
    }


}

void TicTacToeBoard() {
	cout << "" << endl;
	cout << " " << POSITION_1 << " | " << POSITION_2 << " | " << POSITION_3 << " " << endl;

	cout << "---+---+---" << endl;

	cout << " " << POSITION_4 << " | " << POSITION_5 << " | " << POSITION_6 << " " << endl;

	cout << "---+---+---" << endl;

	cout << " " << POSITION_7 << " | " << POSITION_8 << " | " << POSITION_9 << " " << endl;
}

void PLAYER(int player_input, char playerChar) {
	cin >> player_input;
    switch (player_input) {
        case 1:
            POSITION_1 = playerChar;
            break;
        case 2:
            POSITION_2 = playerChar;
            break;
        case 3:
            POSITION_3 = playerChar;
            break;
        case 4:
            POSITION_4 = playerChar;
            break;
        case 5:
            POSITION_5 = playerChar;
            break;
        case 6:
            POSITION_6 = playerChar;
            break;
        case 7:
            POSITION_7 = playerChar;
            break;
        case 8:
            POSITION_8 = playerChar;
            break;
        case 9:
            POSITION_9 = playerChar;
            break;
        default:
            cout << "Please enter a valid position" << endl;
            break;
    }
}

bool winningPositions(char PLAYER) {
	return
	POSITION_1 == PLAYER && POSITION_2 == PLAYER && POSITION_3 == PLAYER || //////////////////////////////
    POSITION_4 == PLAYER && POSITION_5 == PLAYER && POSITION_6 == PLAYER || // Horizontal Wining Positions
    POSITION_7 == PLAYER && POSITION_8 == PLAYER && POSITION_9 == PLAYER || //////////////////////////////
    POSITION_1 == PLAYER && POSITION_4 == PLAYER && POSITION_7 == PLAYER || /////////////////////////////
    POSITION_2 == PLAYER && POSITION_5 == PLAYER && POSITION_8 == PLAYER || // Vertical Winning Positions
    POSITION_3 == PLAYER && POSITION_6 == PLAYER && POSITION_9 == PLAYER || /////////////////////////////
	POSITION_1 == PLAYER && POSITION_5 == PLAYER && POSITION_9 == PLAYER || /////////////////////////////
	POSITION_3 == PLAYER && POSITION_5 == PLAYER && POSITION_7 == PLAYER;  /////////// Diagonal /////////
}

void choosePlayers() {
    switch (player) {
	case X:
        cout << "\nPlayer One: ";
        playersChar = 'X';
		player = O;
		break;
    case O:
        cout << "\nPlayer Two: ";
        playersChar = 'O';
        player = X;
        break;
    }
}

void checkPosition () {

}