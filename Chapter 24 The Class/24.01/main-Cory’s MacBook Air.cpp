#include "TicTacToe.h"

int main() {

    TicTacToe_board newBoard;

    newBoard.setBoard();
    while(1) {
        for (int i = X; i <= O; i++) {
            newBoard.printBoard();
            newBoard.setUserInput(i);
            while (!newBoard.setPlayersMove(i, newBoard.getUserInput())) {
                newBoard.setUserInput(i);
            }
            for (int j = 0; j < newBoard.getBoardSize(); ++j) {
                for (int k = 0; k < newBoard.getBoardSize(); ++k) {

                    newBoard.setCheckPositions(i,j,k, );
                }
            }

        }
    }
}
