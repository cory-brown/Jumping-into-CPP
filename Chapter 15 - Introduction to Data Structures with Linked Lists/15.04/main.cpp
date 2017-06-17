#include <iostream>
#include <string>

using namespace std;

void initBoard(char **, int);           // DONE
void printBoard(char **, int);          // DONE
void player(int, char *, int, char **); // DONE
bool winner(int, char *, int, char **); // DONE
bool playAgain(int, char **, int &);    // DONE
void deleteBoard(char **, int);         // DONE

enum e_player_char { X, O };

int main() {
  const int t_size = 3;
  char player_char[2] = {'X', 'O'};
  bool gameRunning = true;

  char **t_board = new char *[t_size];
  for (int i = 0; i < t_size; i++) {
    t_board[i] = new char[t_size];
  }
  initBoard(t_board, t_size);

  cout << "Player 1 is X" << endl;
  cout << "Player 2 is O" << endl;
  cout << "Player 1 will start first" << endl;
  while (gameRunning) {
    for (int i = X; i < O + 1 && gameRunning; i++) {
      printBoard(t_board, t_size);
      player(i, player_char, t_size, t_board);
      gameRunning = winner(i, player_char, t_size, t_board);
      if (!gameRunning) {
        printBoard(t_board, t_size);
        cout << "Player " << i + 1 << " Wins" << endl;
        gameRunning = playAgain(t_size, t_board, i);
      }
    }
  }
  deleteBoard(t_board, t_size);
}

void initBoard(char **t_board, int t_size) {
  char board_num = '1';
  for (int i = 0; i < t_size; i++) {
    for (int j = 0; j < t_size; j++) {
      t_board[i][j] = board_num++;
    }
  }
}

void printBoard(char **t_board, int t_size) {
  for (int i = 0; i < t_size; i++) {
    for (int j = 0; j < t_size; j++) {
      if (j != 0)
        cout << " | ";
      cout << t_board[i][j];
    }
    if (i != 2)
      cout << "\n---------" << endl;
    else
      cout << endl;
  }
}

void player(int player_num, char *player_char, int t_size, char **t_board) {
  char player_input; // holds the position chosen by the user
  bool space_taken = true;
  char current_position = '0';
  cout << "Player " << player_num + 1 << " : ";
  cin >> player_input;
  while (space_taken) {
    for (int i = 0; i < t_size; i++) {
      for (int j = 0; j < t_size; j++) {
        current_position++; // counter
        if (current_position == player_input) {
          if (t_board[i][j] == player_input) {
            t_board[i][j] = player_char[player_num];
            i = j = t_size;             // Stop loops
            space_taken = !space_taken; // Stop loops
          } else {
            cout << "Space is taken" << endl;
            cout << "Player " << player_num + 1 << " : " << endl;
            cin.ignore();
            cin >> player_input;
            if (player_input < current_position) {
              i = 0;                  // reset loops
              j = -1;                 // reset loops
              current_position = '0'; // reset loops
            }
          }
        }
      }
    }
  }
}

bool winner(int player_num, char *player_char, int t_size, char **t_board) {

  int vc, dc, hc; // Vertical, diagonal and horizontal
  vc = dc = hc = 0;
  bool notWinner = true;

  for (int i = 0; i < t_size; i++) {
    for (int j = 0; j < t_size; j++) {
      if (t_board[j][i] == player_char[player_num]) {
        vc++;
      }
      if (vc == 3) {
        return !notWinner;
      }
    }
  }

  for (int i = 0; i < t_size; i++) {
    for (int j = 0; j < t_size; j++) {
      if (t_board[i][j] == player_char[player_num]) {
        hc++;
      }
      if (hc == 3) {
        return !notWinner;
      }
    }
  }

  for (int i = 0; i < t_size; i++) {
    if (t_board[i][i] == player_char[player_num]) {
      dc++;
    }
    if (dc == 3) {
      return !notWinner;
    }
  }

  dc = 0; // reset diagonal
  int anotherDc = t_size;
  for (int i = 0; i < t_size; i++) {
    if (t_board[i][--anotherDc] == player_char[player_num]) {
      dc++;
    }
    if (dc == 3) {
      return !notWinner;
    }
  }
  return notWinner;
}

bool playAgain(int t_size, char **t_board, int &i) {
  char playerAns;
  cout << "Do you want to play again? y/n" << endl;
  cin >> playerAns;
  if (playerAns == 'y') {
    initBoard(t_board, t_size);
    i = X + 1;
  }
  return playerAns == 'y';
}

void deleteBoard(char **t_board, int t_size) {
  for (int i = 0; i < t_size; i++) {
    delete[] t_board[i];
  }
  delete[] t_board;
}
