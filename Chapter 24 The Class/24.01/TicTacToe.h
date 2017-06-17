//
// Created by Cory Brown on 28/05/2017.
//

#ifndef INC_24_01_TICTACTOE_H
#define INC_24_01_TICTACTOE_H

#include <iostream>
#include <string>
using namespace std;

enum Players {X,O};

class TicTacToe_board {
    private:
    const int _board_size = 3;
    char _board[_board_size][_board_size];
    const char _player_char[2] = {'X', 'O'};
    int _players_num;
    char _players_input = '0';
    bool _game_running = true;


    public:
    void setBoard();
    void printBoard();
    int getPlayersNum();
    void setPlayersNum(const int);
    const char getPlayerChar(const int);
    bool setPlayersMove(const int, const char);
    char getUserInput();
    void setUserInput(const int);
    void setCheckPositions(const int);
    bool isWinner();
    void playAgain();
};

#endif //INC_24_01_TICTACTOE_H
