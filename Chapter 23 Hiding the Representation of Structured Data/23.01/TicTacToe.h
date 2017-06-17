
#ifndef INC_23_01_TICTACTOE_H
#define INC_23_01_TICTACTOE_H

#include <iostream>
#include <string>
using namespace std;

enum e_player_char { X, O };

struct TicTacToe_board {
  int t_size = 3;
  char player_char[2];

  char **t_board;

  void initBoard();           // TODO
  void printBoard();          // TODO
  void player(int); // TODO
  bool winner(int); // TODO
  bool playAgain(int &);    // TODO
  void deleteBoard();         // TODO
};

#endif //INC_23_01_TICTACTOE_H
