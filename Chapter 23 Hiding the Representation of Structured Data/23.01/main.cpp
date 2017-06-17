#include "TicTacToe.h"

int main() {

  bool gameRunning = true;
  TicTacToe_board* newBoard = new TicTacToe_board;

  newBoard->player_char[0] = 'X';
  newBoard->player_char[1] = 'O';
  newBoard->t_board = new char *[newBoard->t_size];
  for (int i = 0; i < newBoard->t_size; i++) {
    newBoard->t_board[i] = new char[newBoard->t_size];
  }

  newBoard->initBoard();

  cout << "Player 1 is X" << endl;
  cout << "Player 2 is O" << endl;
  cout << "Player 1 will start first" << endl;
  while (gameRunning) {
    for (int i = X; i < O + 1 && gameRunning; i++) {
      newBoard->printBoard();
      newBoard->player(i);
      gameRunning = newBoard->winner(i);
      if (!gameRunning) {
        newBoard->printBoard();
        cout << "Player " << i + 1 << " Wins" << endl;
        gameRunning = newBoard->playAgain(i);
      }
    }
  }
  newBoard->deleteBoard();
}
