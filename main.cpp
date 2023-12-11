#include "TicTacToe.h"
int main() {
    TicTacToe game;
    std::string currentPlayer = "Player X";
    int playerXWins = 0;
    int playerOWins = 0;
    bool endGame = false;

    while (!endGame) {
        game.displayBoard();

        int row, col;
        std::cout << currentPlayer << "'s turn. Enter row (1-" << BOARD_SIZE << ") and column (1-" << BOARD_SIZE << "): ";
        std::cin >> row >> col;

        if (game.isValidMove(row, col)) {
            game.makeMove(row, col, currentPlayer[7]);

            if (game.checkWin(currentPlayer[7])) {
                std::cout << currentPlayer << " wins!" << std::endl;
                (currentPlayer == "Player X") ? ++playerXWins : ++playerOWins;

                std::cout << "Current Score: Player X - " << playerXWins << ", Player O - " << playerOWins << std::endl;

                std::cout << "Do you want to continue playing? (y/n): ";
                char continuePlaying;
                std::cin >> continuePlaying;
                if (continuePlaying != 'y' && continuePlaying != 'Y') {
                    endGame = true;
                }
                else {
                    game = TicTacToe(); // Reset the game board
                    currentPlayer = "Player X"; // Reset player to X
                }
            }
            else {
                currentPlayer = (currentPlayer == "Player X") ? "Player O" : "Player X";
            }
        }
        else {
            std::cout << "Incorrect move. Try again." << std::endl;
        }
    }

    return 0;
}