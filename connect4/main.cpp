#include <iostream>
using namespace std;

void board(); // creates the layout and the positions
char players(int player); // assigns them a value and asks them foe they input
void broadPosition(int index); // assigns the users input to the array value
bool winningPosition(int index); // checks if the player has won
void doYouWantPlayAgain(); // asks the use if he wants to play again
//void checkWin(int index); // check of the game is winnable or no

enum TTT {
    R = 0, // player 1 as a const int value R = Red
    B = 1 // player 2 as a const int value B = Blue
};

char gameBoard[5][5]; // an array for the positioning of the game board

char playersChar[] = {'R', 'B'}; // an array for the players characters

int user_input; // the users movement is stored in this variable
string playAgain; // used to store the answer if the player wants to play again
bool gameRunning = true; // is the whole game still running?
bool running = true; // do you want to continue playing
int counter = 0; //counts the squares that have X or O in them

int main() {
    cout << "Welcome to my new Connect 4" << endl;
    cout << "Player One is R" << endl;
    cout << "Player Two is B" << endl;
    cout << "Player One starts first" << endl;
    cout << "Pick the row you want start with" << endl;
//    for(int i=0;i<3;i++){
//        gameBoard[0][i] = 'R'; // a for loop to win the game and debug the game
//    }

    while (gameRunning) {
        while (running){
            for (int i = R; i <= B; ++i) {
                players(i);
                broadPosition(i);
                counter++; // counter to check if the game is a tie
                board();
                // checkWin(i);
                if (!winningPosition(R)) {
                    break;
                }
                winningPosition(B);
            }
        }
        doYouWantPlayAgain();
    }
    cout << "\nThank you for playing :-)" << endl;
}

/*
 * Generating the 'Connect 4' board
 */
void board(){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << " " << gameBoard[i][j]; // prints the values of the array onto the board
            if (j == 5 - 1) { // this is to end line at the end of the board
                cout << "" << endl;
                for (int k = 0; k < 5; ++k) {
                    if (i != 5 - 1) { // this is to stop the dashes from printing at the bottom
                        cout << "---";
                        if (k != 5 - 1){ // this is to stop the pluses from printing on the end of each line and at the bottom
                            cout << "+";
                        } // if
                    } // if
                } // for
                cout << endl; // this is to put the pipe chars underneath the lines and pluses
            } else if (j != 5) {
                cout << " |";
            }

        }
    }
} // DONE

/*
 *  Asking the player for a move and storing in to the 'user_input' variable
 */
char players(int player){
    cout << "\nPlayer " << player + 1 << ": ";
    cin >> user_input;
    return playersChar[player];
} // DONE

/*
 * taking users input and placing the players character on the board
 */
void broadPosition(int index) {
    int x = 4;
    for (int i = 1; i <= 5; i++) { // ' <= ' is for the users input
        if (i == user_input) {
            while (true) {
                if (gameBoard[x][i - 1] == playersChar[0] ||
                    gameBoard[x][i - 1] == playersChar[1]) {
                    x--;
                } else {
                    gameBoard[x][i - 1] = playersChar[index];
                    break;
                }
            }
        }
    }
} // DONE

/*
 *  Checking the position of the players characters to see if player has won
 */
bool winningPosition(int index) {
    int h = 0; // this variable is used as a counter for horizontal lines
    int v = 0; // this variable is used as a counter for vertical lines
    int vc = 0; // this variable is used as a counter for vertical lines
    int d = 0;
/*
 * WIN
 */
    for (int i = 4; i > -1; i--) {
        for (int j = 4; j > -1; j--) {
            // start of horizontal winning combination
            if (gameBoard[i][j] == playersChar[index]) {
                h++;
                if (h == 4) {
                    running = false;
                }
                if (j == 0) {
                    h = 0;
                }
            } else {
                h = 0;
            }
            //end of horizontal winning combination

            // start of vertical winning combination
            if (gameBoard[4][j] == playersChar[index] || gameBoard[3][j] == playersChar[index]) {
                v = j;
                for (int k = 4; k > -1; k--) {
                    if (gameBoard[k][v] == playersChar[index]) {
                        vc++;
                        if (vc == 4) {
                            running = false;
                        }
                        if (k == 0) {
                            vc = 0;
                        }
                    } else {
                        vc = 0;
                    }
                    cout << k << v << " vc " << vc << endl;
                }
                cout << endl;
            }// end of vertical winning combination


        } // TODO: need to fix diagonal win combination
    }
    if (!running) {
        cout << "Player " << index + 1 << " Wins" << endl;
    }
    return running;

//    /*
//     * TIE
//     */
//    for (int l = 0; l < 3; ++l) {
//        for (int i = 0; i < 3; ++i) {
//            if (gameBoard[l][i] == playersChar[0] || gameBoard[l][i] == playersChar[1]) {
//                if (counter == 9){
//                    cout << "Tie" << endl;
//                    running = false;
//                }
//            }
//        }
//    }
//
} // TODO
/*
 *  Checks if the player wants to player another game
 */
void doYouWantPlayAgain() {
    cout << "\nDo you want to play another game" << endl;
    cout << "Yes/No" << endl;
    cin >> playAgain;
    if (playAgain == "Yes" || playAgain == "yes" || playAgain == "YES") {
        gameRunning = true;
        running = true;
        counter = 0;
        for (int i=0;i<3;++i) {
            for (int j=0;j<3;++j) {
                gameBoard[i][j] = NULL; // flush the array of values
            }
        }
    }  else {
        gameRunning = false;
    }
} // TODO not flushing the array

/*
void checkWin(int index) {
    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 3; ++k) {
            if (counter == 8) {
                if (!(gameBoard[i][k] == playersChar[index] && gameBoard[i][k + 1] == playersChar[index] &&
                    gameBoard[i][k + 2] == playersChar[index] || // vertically
                    gameBoard[k][i] == playersChar[index] && gameBoard[k + 1][i] == playersChar[index] &&
                    gameBoard[k + 2][i] == playersChar[index] ||// horizontally
                    gameBoard[k][k] == playersChar[index] && gameBoard[k + 1][k + 1] == playersChar[index] &&
                    gameBoard[k + 2][k + 2] == playersChar[index] || // diagonally
                    gameBoard[0][k + 2] == playersChar[index] && gameBoard[1][k + 1] == playersChar[index] &&
                    gameBoard[2][k] == playersChar[index])) {

                        cout << "\n Game cannot be won" << endl;
                }
            }
        }
    }
}
 */ // TODO