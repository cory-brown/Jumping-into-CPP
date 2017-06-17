#include "TicTacToe.h"

void TicTacToe_board::setBoard() {
    cout << "Player 1 is X" << endl;
    cout << "Player 2 is O" << endl;
    cout << "Player 1 will start first" << endl;

    char board_num = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            _board[i][j] = board_num++;
        }
    }
};

void TicTacToe_board::printBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << _board[i][j] << " ";
        }
        cout << endl;
    }
};

int TicTacToe_board::getBoardSize() {
    return _board_size;
};

void TicTacToe_board::setPlayersNum(const int player) {
    _players_num = player;
};

int TicTacToe_board::getPlayersNum() {
    return _players_num;
};

const char TicTacToe_board::getPlayerChar(const int player_num) {
    return _player_char[player_num];
};

bool TicTacToe_board::setPlayersMove(const int player_num, const char player_input) {
    char position_counter = '0';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ++position_counter;
            if (player_input == position_counter) {
                if (_board[i][j] == getPlayerChar(X) || _board[i][j] == getPlayerChar(O)) {
                    cout << "Position Taken. Please choose another one" << endl;
                    return false;
                }
                _board[i][j] = getPlayerChar(player_num);
                return true;
            }
        }
    }
    return false;
};

char TicTacToe_board::getUserInput() {
    return _players_input;
};

void TicTacToe_board::setUserInput(const int player_num) {
    setPlayersNum(player_num + 1);
    cout << "Player " << getPlayersNum() << " : ";
    cin >> _players_input;
    cin.ignore();
};

void TicTacToe_board::setCheckPositions(const int player_num, const int row, const int col) {
    int vc, dc, hc; // Vertical, diagonal and horizontal
    vc = dc = hc = 0;
    for (int i = 0; i < _board_size; i++) {
        for (int j = 0; j < _board_size; j++) {
            if (_board[j][i] == _player_char[player_num]) {
                vc++;
            }
            if (vc == _board_size) {
                return !_game_running;
            }
        }
    }

    for (int i = 0; i < _board_size; i++) {
        for (int j = 0; j < _board_size; j++) {
            if (_board[i][j] == _player_char[player_num]) {
                hc++;
            }
            if (hc == _board_size) {
                return !game_running;
            }
        }
    }

    for (int i = 0; i < _board_size; i++) {
        if (_board[i][i] == _player_char[player_num]) {
            dc++;
        }
        if (dc == _board_size) {
            return !game_running;
        }
    }

    dc = 0; // reset diagonal
    int anotherDc = _board_size;
    for (int i = 0; i < _board_size; i++) {
        if (_board[i][--anotherDc] == _player_char[player_num]) {
            dc++;
        }
        if (dc == _board_size) {
            return !game_running;
        }
    }
    return game_running;
}






