#include <iostream>

using namespace std;

void printBoard(int size);
void startPositions(int size);
void player(int index);
int pickChecker(int playerTurn);

char gameBoard[8][8];

char playersChar[] = {'R','B'};
int checkersPiece;
char position;

enum PLAYERS {
    R = 0,
    B = 1
};

int main() {
    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 8; ++i) {
            gameBoard[j][i] = ' '; // this is to stop the little square showing up when using the Xcode compiler
        }
    }
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
            if (j % 2 == 0 && i % 2 == 0) {
                gameBoard[i][j] = playersChar[0];
            } else if (j % 2 != 0 && i % 2 != 0) {
                gameBoard[i][j] = playersChar[0];
            }
        }
    }
    for (int i = size; i > 4; i--) {
        for (int j = size - 1; j > - 1; j--) {
            if (j % 2 == 0 && i % 2 == 0) {
                gameBoard[i][j] = playersChar[1];
            } else if (j % 2 != 0 && i % 2 != 0) {
                gameBoard[i][j] = playersChar[1];
            }
        }
    }
}

void player(int index) {
    cout << "\nPlayer " << index + 1 << endl;
    cout << "Which checker do you want to move" << endl;
    cin >> checkersPiece;
    cout << "Left or Right" << endl;
    cout << "l/r or L/R" << endl;
    cin >> position;
}

int pickChecker(int playerTurn) {
    int k = 0;
    int row, column;
    if (playerTurn == 0) {
        for (int i = 2; i >= 0; --i) {
            for (int j = 7; j >= 0; --j) {
                if (gameBoard[i][j] == playersChar[0]) {
                    k++;
                    cout << "i " << i << endl;
                    cout << "j " << j << endl;
                    cout << "k " << k << endl;
                    if (k == checkersPiece) {
                        row = i;
                        column = j;
                        return gameBoard[row][column];
                    }
                }
            }
        }
    }
//    } else {
//        for (int i = 0; i < size; ++i) {
//            for (int j = 0; j < size; ++j) {
//                if () {
//                    k++;
//                    if (k == checkersPiece) {
//
//                    }
//                }
//            }
//        }
//    }
    return 0;
}


void direction(int playerTurn) {
    if (position == 'l' || position == 'L') {
        pickChecker(playerTurn);
    } else if (position == 'r' || position == 'R') {

    }
}