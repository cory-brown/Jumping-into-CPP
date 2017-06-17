/*

Jumping into C++

Chapter 14
Practice Problem

5. Write a two-player game of "connect 4"31 where the user can set the width and height of the
board and each player gets a turn to drop a token into the slot. Display the board using + for one
side, x for the other, and _ to indicate blank spaces.

*/

#include <iostream>

using namespace std;

void startGame(int &h, int &w);
void setBlankGrid (string ** connect4Grid, int h, int w); // This set all of positions to "_"
void printGrid (string ** connect4Grid, int h, int w); // Prints the grid
void playersTurn(int player); // Takes input of player
int checkPosition (string ** connect4Grid, int h, int w, int player); // Uses the input from the user, check the input against the grid and inserts it into the grid
bool checkWinningPositions (string ** connect4Grid, int h, int w, int player); // This checks the the winning combinations against the grid to check if the player has won
bool playAgain (bool gameRunning); // Does the user want to play again?
void flushGrid(string ** connect4Grid, int h);


enum THEPLAYERVAL {
    PLUS = 1,
    CROSS = 2
};

const string playersChars[] = {"+", "x"};
int playersChoice = 0;

int main() {
    bool gameRunning = true;
    int h = 0, w = 0;

    startGame(h, w);
    string ** connect4Grid = new string * [h];
    for (int i = 0; i < h; ++i) {
        connect4Grid[i] = new string [w];
    }
    setBlankGrid(connect4Grid,h,w);
    printGrid(connect4Grid,h,w);
    while (gameRunning) {
        for (int i = PLUS; (i <= CROSS) && (gameRunning); ++i) {
            playersTurn(i);
            if (checkWinningPositions(connect4Grid, h, w, i)) {
                gameRunning = !gameRunning;
            }
            printGrid(connect4Grid,h,w);
            if (!gameRunning) {
                cout << "\nPlayer " << i << " Wins" << endl;
            }
        }
        if (!gameRunning) {
            if ((gameRunning = playAgain(gameRunning))){
                startGame(h, w);
                setBlankGrid(connect4Grid,h,w);
                printGrid(connect4Grid,h,w);
            }
        }
    }
    cout << "\nThanks for playing" << endl;
    flushGrid(connect4Grid, h);
}

void startGame(int &h, int &w) {
    while (h <= 3 && w <= 3) {
        cout << "Set height: ";
        cin >> h;
        cout << "Set Width: ";
        cin >> w;
        if (h <= 3 && w <= 3) {
            cout << "The height and width must be greater than three" << endl;
        }
    }

    cout << "Player one is +" << endl;
    cout << "Player two is x" << endl;
    cout << "Pick one of the columns to start" << endl;
}

void setBlankGrid (string ** connect4Grid, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            connect4Grid[i][j] = "_";
        }
    }
}

void printGrid (string ** connect4Grid, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << connect4Grid[i][j] << " ";
        }
        cout << endl;
        if (i == h - 1) {
            for (int j = 0; j < w; ++j) {
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
}

void playersTurn(int player) {
    cout << "Player " << player << ": ";
    cin >> playersChoice;
}

int checkPosition (string ** connect4Grid, int h, int w, int player) {
    int heightCounter = h-1;
    bool positionTaken = true; // used to check if the position is taken
    while (positionTaken) {
        for (int i = w - 1; i >= 0; --i) {
            if (playersChoice == i + 1) { // if the columns matches the players input
                if (connect4Grid[heightCounter][i] == "_") {
                    connect4Grid[heightCounter][i] = playersChars[player-1]; // adds the players character into the grid
                    positionTaken = !positionTaken; // flips the positionTaken variable to false
                } else if (connect4Grid[0][i] == playersChars[0] || connect4Grid[0][i] == playersChars[1]) { // checks if the column is full
                    cout << "This column is full, please choose another." << endl;
                    playersTurn(player); // asks for players input
                } else if (connect4Grid[heightCounter][i] == playersChars[0] || connect4Grid[heightCounter][i] == playersChars[1]) { // checks if any of the players are in said input
                    heightCounter--; // decrements the heightCounter and moves up a row
                }
            }
        }
    }
    return heightCounter;
}

bool checkWinningPositions (string ** connect4Grid, int h, int w, int player) {
    int heightCounter = checkPosition(connect4Grid, h, w, player); // This function is called here, also the value is assigned to this variable
    int vc = 0; // Vertical Counter
    int hc = 0; // Horizontal Counter
    int dc = 0; // Diagonal Counter
    bool winner = false;

    /****************************************
    *********** START OF Vertical ***********
    ****************************************/

    if (heightCounter <=  (h - 4)) { // This makes sure the player is a least 4 counters high
        for (int k = 0; k < h; k++) {
            if (connect4Grid[k][playersChoice-1] == playersChars[player-1]) {
              vc++;
              if (vc == 4) {
                winner = !winner;
              }
            } else {
              vc = 0;
            }
        }
    }

    /****************************************
    *********** END OF Vertical ***********
    ****************************************/

    /****************************************
    *********** START OF Horizontal ***********
    ****************************************/

    for (int k = 0; k < w; k++) {
        if (connect4Grid[heightCounter][k] == playersChars[player - 1]) {
          hc++;
          if (hc == 4) {
            winner = !winner;
          }
        } else {
          hc = 0;
        }
    }

  /****************************************
  *********** END OF Horizontal ***********
  ****************************************/

  /****************************************
  *********** START OF Diagonal ***********
  ****************************************/

  if (heightCounter <=  (h - 4)) { // This makes sure the player is a least 4 counters high
    int playersPosition = (playersChoice - 1);
    for (int i = heightCounter; i < (h - 1); i++) {
      if ((connect4Grid[i][playersPosition] == playersChars[player-1])) {
        playersPosition++;
        dc++;
        if (dc == 4) {
          winner = !winner;
        }
      } else {
        dc = 0;
      }
    }

    for (int i = heightCounter; i < (h - 1); i++) {
      if ((connect4Grid[i][playersPosition] == playersChars[player-1])) {
        playersPosition--;
        dc++;
        if (dc == 4) {
          winner = !winner;
        }
      } else {
        dc = 0;
      }
    }
  }

  /****************************************
  ************ END OF Diagonal ************
  ****************************************/

  return winner;
}

bool playAgain (bool gameRunning) {
    char answer;
    cout << "Do you want to play again? Y/N" << endl;
    cin >> answer;
    if ((answer == 'Y') || (answer == 'y')) {
        gameRunning = true;
    }
    return gameRunning;
}

void flushGrid(string ** connect4Grid, int h) {
    for (int i = 0; i < h; ++i) {
        delete [] connect4Grid[i];
    }
    delete [] connect4Grid;
}
