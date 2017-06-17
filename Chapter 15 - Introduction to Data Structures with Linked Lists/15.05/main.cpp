#include <iostream>

using namespace std;

struct t_board {
  int position;
  char player_char = 'N';
  t_board *next;
}; // Linked List

t_board *head = NULL; // Head of the list

void buildBoard(int);                      // DONE
void printBoard();                         // DONE
void player(int, char *);                  // DONE
bool checkWin(int, char *, int); // TODO
//bool winningPosition(int, char *, int); // TODO

enum PLAYERS { X, O };

int main() {
  char player_chars[] = {'X', 'O'}; // Players Characters
  bool gameRunning = true;

  cout << "Player 1 is X" << endl;
  cout << "Player 2 is O" << endl;
  cout << "Player 1 will start first" << endl;
  for (int i = 0; i < 9; i++) {
    buildBoard(i);
  }
  printBoard();
  while (gameRunning) {
    for (int i = X; i <= O && gameRunning; ++i) {
      player(i, player_chars);
      printBoard();

			gameRunning = checkWin(i, player_chars, 4);

      // this method doesn't work and looks ugly thing of some thing with for
      // loops and incrementing to the next value
      // e.g the first 3 calls could be incremented by 4 and the next 3 calls
      // could be just a normal for loop
    }
  }
}

void buildBoard(int i) {
  t_board *add_position = new t_board; //
  t_board *next_position = head;

  add_position->position = i + 1;

  if (head == NULL) {
    add_position->next = head;
    head = add_position;
  } else {
    while (next_position != NULL) {
      if (next_position->next == NULL) {
        next_position->next = add_position;
        add_position->next = NULL;
      }
      next_position = next_position->next;
    }
  }
}

void printBoard() {
  t_board *position_it = head;

  while (position_it != NULL) {
    if (position_it->player_char != 'N') {
      cout << position_it->player_char;
    } else {
      cout << position_it->position;
    }

    if (position_it->position % 3 == 0) {
      cout << endl;
      if (position_it->position != 9) {
        cout << "---------" << endl;
      }
    } else {
      cout << " | ";
    }
    position_it = position_it->next; // move to next node
  }
}

void player(int player, char *player_chars) {
  int player_input;
  cout << "Player " << player + 1 << " :";
  cin >> player_input;

  t_board *position_it = head;
  while (position_it != NULL) {
    if (position_it->position == player_input) {
      position_it->player_char = player_chars[player];
      break;
    } else {
      position_it = position_it->next;
    }
  }
}

bool checkWin(int player, char *player_chars, int pos) {
    for (int i = 0; i < 3; ++i) {
        
    }
}
