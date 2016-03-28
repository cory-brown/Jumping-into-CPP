#include <iostream>

using namespace std;

void board(); // creates the layout and the positions
char players(int player); // assigns them a value and asks them foe they input
void broadPosition(int index); // assigns the users input to the array value
bool winningPosition(int index); // checks if the player has won
bool checkPosition(int index); // check to see if the player uses a valid movement
void doYouWantPlayAgain(); // asks the use if he wants to play again
//void checkWin(int index); // check of the game is winnable or no

enum TTT {
    X = 0, // player 1 as a const int value
    O = 1 // player 2 as a const int value
};

char gameBoard[3][3]; // an array for the positioning of the game board
char playersChar[] = {'X', 'O'}; // an array for the players characters
int user_input; // the users movement is stored in this variable
string playAgain; // used to store the answer if the player wants to play again
bool gameRunning = true; // is the whole game still running?
bool running = true; // do you want to continue playing
bool positionTaken = true; // is position taken?
int counter = 0; //counts the squares that have X or O in them

int main() {
    cout << "Welcome to my new TicTacToe" << endl;
    cout << "Player One is X" << endl;
    cout << "Player Two is O" << endl;
    cout << "Player One starts first" << endl;
//    for(int i=0;i<3;i++){
//        gameBoard[0][i] = 'X'; // a for loop to win the game and debug the game
//    }
    while (gameRunning) {
        while (running){
            for (int i = X; i <= O; ++i) {
                players(i);
                positionTaken = true;
                while (positionTaken) {
                    checkPosition(i);
                }
                broadPosition(i);
                counter++; // counter to check if the game is a tie
                board();
               // checkWin(i);
                if (!winningPosition(X)) {
                    break;
                }
                winningPosition(O);
            }
        }
        doYouWantPlayAgain();
    }
    cout << "\nThank you for playing :-)" << endl;
}

void board(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) {
            cout << " " << gameBoard[i][j];
            if (j == 2 && i != 2) {
                cout << "" << endl;
                cout << "---+---+---" << endl;
            } else if(j != 2){
                cout << " |";
            }
        }
    }
}

char players(int player){
    cout << "\nPlayer " << player + 1 << ": ";
    cin >> user_input;
    return playersChar[player];
}

void broadPosition(int index) {
    int c = 0;
    for (int i=1;i<=user_input;i++) {
        if (user_input == i) {
            for (int j=0;j<3;++j) {
                for (int k=0;k<3;++k) {
                    c++;
                    if(c == user_input) {
                        gameBoard[j][k] = playersChar[index];
                    }
                }
            }
        }
    }
}

bool winningPosition(int index) {
    int k = 0;
    int j = 3; // runs like a back loop for the diagonal
    for (int i = 0; i < 3; i++) {
        j--;
        if (gameBoard[i][k] == playersChar[index] && gameBoard[i][k + 1] == playersChar[index] && gameBoard[i][k + 2] == playersChar[index]|| // vertically
            gameBoard[k][i] == playersChar[index] && gameBoard[k + 1][i] == playersChar[index] && gameBoard[k + 2][i] == playersChar[index]||// horizontally
            gameBoard[k][k] == playersChar[index] && gameBoard[k + 1][k + 1] == playersChar[index] && gameBoard[k + 2][k + 2] == playersChar[index] || // diagonally
            gameBoard[0][k+2] == playersChar[index] && gameBoard[1][k+1] == playersChar[index] && gameBoard[2][k] == playersChar[index]){  // diagonally
            if (playersChar[0]) {
                cout << "\nPlayer 1  Wins" << endl;
                running = false;
                break;
            } else if(playersChar[1]) {
                cout << "\nPlayer 2  Wins" << endl;
                running = false;
                break;
            }
        }
    }
    for (int l = 0; l < 3; ++l) {
        for (int i = 0; i < 3; ++i) {
            if (gameBoard[l][i] == playersChar[0] || gameBoard[l][i] == playersChar[1]) {
                if (counter == 9){
                    cout << "Tie" << endl;
                    running = false;
                }
            }
        }
    }
    return running;
}

bool checkPosition(int index) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            k++;
            if(gameBoard[i][j] == playersChar[0]||
               gameBoard[i][j] == playersChar[1]){
               if (k == user_input) {
                   cout << "Position taken" << endl;
                   players(index);
                   k = 0;
                   j = -1; // for some wried reason it -1 not 0
               }
           }
        }
    }
    positionTaken = false; // this is not a mistake
    return positionTaken;
}

void doYouWantPlayAgain() {
    cout << "\nDo you want to play another game" << endl;
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
}

//void checkWin(int index) {
//    for (int i = 0; i < 3; ++i) {
//        for (int k = 0; k < 3; ++k) {
//            if (counter == 8) {
//                if (!(gameBoard[i][k] == playersChar[index] && gameBoard[i][k + 1] == playersChar[index] &&
//                    gameBoard[i][k + 2] == playersChar[index] || // vertically
//                    gameBoard[k][i] == playersChar[index] && gameBoard[k + 1][i] == playersChar[index] &&
//                    gameBoard[k + 2][i] == playersChar[index] ||// horizontally
//                    gameBoard[k][k] == playersChar[index] && gameBoard[k + 1][k + 1] == playersChar[index] &&
//                    gameBoard[k + 2][k + 2] == playersChar[index] || // diagonally
//                    gameBoard[0][k + 2] == playersChar[index] && gameBoard[1][k + 1] == playersChar[index] &&
//                    gameBoard[2][k] == playersChar[index])) {
//
//                        cout << "\n Game cannot be won" << endl;
//                }
//            }
//        }
//    }
//}