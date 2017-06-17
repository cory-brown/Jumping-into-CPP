#include "TicTacToe.h"

void TicTacToe_board::initBoard() {
  char board_num = '1';
  for (int i = 0; i < t_size; i++) {
    for (int j = 0; j < t_size; j++) {
      t_board[i][j] = board_num++;
    }
  }
}


void TicTacToe_board::printBoard() {
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

void TicTacToe_board::player(int player_num) {
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

bool TicTacToe_board::winner(int player_num) {

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

bool TicTacToe_board::playAgain(int &i) {
  char playerAns;
  cout << "Do you want to play again? y/n" << endl;
  cin >> playerAns;
  if (playerAns == 'y') {
    TicTacToe_board::initBoard();
    i = X + 1;
  }
  return playerAns == 'y';
}

void TicTacToe_board::deleteBoard() {
  for (int i = 0; i < t_size; i++) {
    delete[] t_board[i];
  }
  delete[] t_board;
}
