#include "TicTacToe.h"

int main() {

    TicTacToe_board newBoard;

    newBoard.setBoard();
    while(newBoard.isWinner()) {
        for (int i = X; i <= O && newBoard.isWinner(); i++) {
            newBoard.printBoard();
            newBoard.setUserInput(i);
            while (!newBoard.setPlayersMove(i, newBoard.getUserInput())) {
                newBoard.setUserInput(i);
            }
            newBoard.setCheckPositions(i);
            if (!newBoard.isWinner()) {
                newBoard.printBoard();
                cout << "Player " << (i + 1) << " wins" << endl;
                newBoard.playAgain();
            }
        }
    }
}
