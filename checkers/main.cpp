#include <iostream>

using namespace std;

void printBoard(int size);
void startPositions(int size);
void player(int index);
void pickChecker(int playerTurn);

char gameBoard[8][8];

char playersChar[] = {'R', 'B'};
int columnOfPiece;
int rowOfPiece;
char position;

enum PLAYERS {
    R = 0,
    B = 1
};

int main() {

    cout << "Welcome to my checkers game" << endl;
    cout << "Player 1 is 'R'" << endl;
    cout << "Player 2 is 'B'" << endl;
    cout << "You play by selecting the counter that you want to move" << endl;
    cout << "Checkers piece 1 to 12" << endl;
    cout << "Then selecting a direction" << endl;
    cout << "'L' for Left" << endl;
    cout << "'R' for Right" << endl;
    while (true) {
        startPositions(8); // places the checkers in the default position
        printBoard(8);
        for (int i = R; i <= B; ++i) {
            player(i);
            pickChecker(i);
            printBoard(8);
        }
    }
}

void printBoard(int size) {
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < size; ++k) {
            cout << "---- ";
        }
        cout << endl;
        for (int j = 0; j < size; ++j) {
            cout << "| "<< gameBoard[i][j] << " |" ;
        }
        cout << endl;
        if (i == size - 1) {
            for (int j = 0; j < size; ++j) {
                cout << "---- ";
            }
        }
    }
}

void startPositions(int size) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; ++j) {
            if (j % 2 == 0 && i % 2 == 0) { // odd tile space
                gameBoard[i][j] = playersChar[0];
            } else if (j % 2 != 0 && i % 2 != 0) { // even tile space
                gameBoard[i][j] = playersChar[0];
            }
        }
    }
    for (int i = size; i > 4; i--) {
        for (int j = size - 1; j > - 1; j--) {
            if (j % 2 == 0 && i % 2 == 0) {// odd tile space
                gameBoard[i][j] = playersChar[1];
            } else if (j % 2 != 0 && i % 2 != 0) { // even tile space
                gameBoard[i][j] = playersChar[1];
            }
        }
    }
}

void player(int index) {
    cout << "\nPlayer " << index + 1 << endl;
    cout << "Which checker do you want to move" << endl;
    cout << "What is the column number?" << endl;
    cin >> columnOfPiece;
    cout << "What is the row number?" << endl;
    cin >> rowOfPiece;
    cout << "Left or Right" << endl;
    cout << "l/r or L/R" << endl;
    cin >> position;
}

void pickChecker(int playerTurn) {
    for (int i = 0; i < 8; ++i) { // column
        for (int j = 0; j < 8; ++j) { // row
            if (gameBoard[i][j] == playersChar[playerTurn]) {
                if (i + 1 == columnOfPiece && j + 1 == rowOfPiece) { //
                    if (position == 'l' || position == 'L') {
                        gameBoard[i][j] = ' ';
                        if (playerTurn == R) {
                            gameBoard[i+1][j-1] = playersChar[playerTurn];
                            // this is the left direction for 'R' (Player 1)
                        } else {
                            gameBoard[i-1][j-1] = playersChar[playerTurn];
                            // this is the left direction for 'B' (Player 2)
                        }
                    } else if (position == 'r' || position == 'R') {
                        gameBoard[i][j] = ' ';
                        if (playerTurn == R) {
                            gameBoard[i+1][j+1] = playersChar[playerTurn];
                            // this is the right direction for 'R' (Player 1)
                        } else {
                            gameBoard[i-1][j+1] = playersChar[playerTurn];
                            // this is the right direction for 'B' (Player 2)
                        }
                    }
                }
            }
        }
    }
}