#include <iostream>

using namespace std;

void printBoard(int size);
void startPositions(int size);
void player(int index);
void pickChecker(int playerTurn);
void flushBoard();
bool scoring();
void kinging();
void is_king(int index);

char gameBoard[8][8];
char playersChar[] = {'R', 'B', 'K', 'Q'};

/*
 * the players characters
 * 'R' is P1, 'B' is P2, 'K' is P1 King, 'Q' is P2 King
*/
int columnOfPiece;
int rowOfPiece;
int scoreP1 = 0;
int scoreP2 = 0;
char position;
char kingDirection;
bool running = true;

enum PLAYERS {
    R = 0,
    B = 1
};

int main() {
    cout << "Welcome to my checkers game" << endl;
    cout << "Player 1 is 'R'" << endl;
    cout << "Player 2 is 'B'" << endl;
    cout << "You play by selecting the column and row of the checkers piece that you want to move" << endl;
    cout << "Checkers board is 8x8" << endl;
    cout << "Then selecting a direction" << endl;
    cout << "'L' or 'l' for Left" << endl;
    cout << "'R' or 'r' for Right" << endl;
    flushBoard(); // flush the board
    while (running) {
        startPositions(8); // places the checkers in the default position
        printBoard(8); // print the board to the console
        while (running) {
            for (int i = R; i <= B; ++i) {
                if (!scoring()) {
                    break;
                }
                for (int k = 2; k < 4; ++k) {
                    is_king(k);
                }
                player(i);
                for (int j = 0; j < 4; ++j) {
                    pickChecker(j);
                }
                kinging();
                printBoard(8);
            }
        }
    }
}


// TODO: add a jumping function for when you take one of your opponent's
// checkers and also check for an extra jump and you can't stop jumping until no more are available


void printBoard(int size) {
    int columnNumber = 1;
    int rowNumber = 1;
    for (int i = 0; i < size; ++i) {
        for (int l = 0; l < size; ++l) {
            if (i == 0) {
                cout << "  " << columnNumber++ << "  "; // this is to print the numbers at the top
            }
        }
        if (i == 0) // this is to end line when the numbers at the top finish
            cout << endl;
        for (int k = 0; k < size; ++k) {
            cout << "---- "; //
        }
        cout << endl;
        for (int j = 0; j < size; ++j) {
            cout << "| "<< gameBoard[i][j] << " |" ; // print the numbers between the
            if (j == 7)
                cout << " " << rowNumber++;
        }
        cout << endl;
        if (i == size - 1) {
            for (int j = 0; j < size; ++j) {
                cout << "---- "; // this is to print the lines at the bottom of the board
            }
        }
    }
}

void startPositions(int size) {
    for (int i = 0; i < 3; i++) { // R
        for (int j = 0; j < size; ++j) {
            if (j % 2 == 0 && i % 2 == 0) { // odd tile space
                gameBoard[i][j] = playersChar[0];
            } else if (j % 2 != 0 && i % 2 != 0) { // even tile space
                gameBoard[i][j] = playersChar[0];
            }
        }
    }
    for (int i = size; i > 4; i--) { // B
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
    cout << "\nPieces left";
    cout << "\nPlayer 1: " << scoreP1 << endl;
    cout << "Player 2: " << scoreP2 << endl;
    cout << "\nPlayer " << index + 1 << endl;
    cout << "Which checker do you want to move" << endl;
    cout << "What is the column number?" << endl;
    cin >> columnOfPiece;
    cout << "What is the row number?" << endl;
    cin >> rowOfPiece;
    cout << " ⬅ Left or ➡ Right" << endl;
    cout << "l/r or L/R" << endl;
    cin >> position;
}

void pickChecker(int playerTurn) { //  TODO: add the king movement into this e.g. combine them
    for (int i = 0; i < 8; ++i) { // row
        for (int j = 0; j < 8; ++j) { // column
            if (gameBoard[i][j] == playersChar[playerTurn]) {
                if (i + 1 == rowOfPiece && j + 1 == columnOfPiece) { //
                    if (position == 'l' || position == 'L') {
                        gameBoard[i][j] = ' ';
                        if (playerTurn == R || (kingDirection == 'f' || kingDirection == 'F' && playersChar[2] == 'K')) {
                            gameBoard[i + 1][j - 1] = playersChar[playerTurn];
                            // this is the left direction for 'R' (Player 1) direction: \^ // forward left
                        } else if (playerTurn == B || (kingDirection == 'b' || kingDirection == 'B' && playersChar[2] == 'K')) {
                            gameBoard[i - 1][j - 1] = playersChar[playerTurn];
                            // this is the left direction for 'B' (Player 2) direction: /v // backward left
                        }
                    } else if (position == 'r' || position == 'R') {
                        gameBoard[i][j] = ' ';
                        if (playerTurn == R || (kingDirection == 'f' || kingDirection == 'F' && playersChar[2] == 'K')) {
                            gameBoard[i+1][j+1] = playersChar[playerTurn];
                            // this is the right direction for 'R' (Player 1) direction: /^ forward right
                        } else if (playerTurn == B) {
                            gameBoard[i-1][j+1] = playersChar[playerTurn];
                            // this is the right direction for 'B' (Player 2) direction: \v backward right
                        }
                    }
                }
            }
        }
    }
}

void flushBoard() {
    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 8; ++i) {
            gameBoard[j][i] = ' ';
        }
    }
    // this 'for' loop is to remove the little squares from the game board, when using the Xcode compiler
}

bool scoring() {
    scoreP1 = 0;
    scoreP2 = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (gameBoard[i][j] == playersChar[0] || gameBoard[i][j] == playersChar[2]) {
                scoreP1++;
            } else if (gameBoard[i][j] == playersChar[1]|| gameBoard[i][j] == playersChar[3]) {
                scoreP2++;
            }
        }
    }
    for (int j = 0; j > 8; ++j) {
        if (gameBoard[7][j] == playersChar[2]) {
            scoreP1++;
        } else if (gameBoard[0][j] == playersChar[2]){
            scoreP2++;
        }
    }
    for (int k = 0; k < 8; ++k) {
        for (int i = 0; i < 8; ++i) {
            if (scoreP1 == 0 || scoreP2 == 0) {
                running = !running;
            }
        }
    }
    return running;
}

void kinging() {
    for (int i = 0; i < 8; ++i) {
        if (playersChar[0] == gameBoard[3][i]) {
            gameBoard[3][i] = playersChar[2]; // 'K' // gameBoard[7][i] <- TODO change it to this
        } else if (playersChar[1] == gameBoard[0][i]) {
            gameBoard[0][i] = playersChar[3]; // 'Q'
        }
    }
}

void is_king(int index) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (gameBoard[i][j] == playersChar[index]) {
                cout << "\nYou have selected a King" << endl;
                cout << "Which direction do you which to go?" << endl;
                cout << " ⬆ Forward or ⬇ Backwards?" << endl;
                cout << "F/B or f/b" << endl;
                cin >> kingDirection;
            }
        }
    }
}