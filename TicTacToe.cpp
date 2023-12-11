#include "TicTacToe.h"


TicTacToe::TicTacToe() : board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' ')) {}

TicTacToe::TicTacToe(const TicTacToe& other) : board(other.board) {}

TicTacToe& TicTacToe::operator=(const TicTacToe& other) {
    if (this != &other) {
        board = other.board;
    }
    return *this;
}

bool TicTacToe::operator==(const TicTacToe& other) const {
    return board == other.board;
}

void TicTacToe::displayBoard() const {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j];
            if (j < board[i].size() - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < board.size() - 1) {
            std::cout << "---------" << std::endl;
        }
    }
}

bool TicTacToe::isValidMove(int row, int col) const {
    return row >= 1 && row <= BOARD_SIZE &&
        col >= 1 && col <= BOARD_SIZE &&
        board[row - 1][col - 1] == ' ';
}
void TicTacToe::makeMove(int row, int col, char currentPlayer) {
    if (isValidMove(row, col)) {
        board[row - 1][col - 1] = currentPlayer;
    }
}

bool TicTacToe::checkWin(char playerSymbol) const {
    // Поиск выигрышной комбинации

        // Поиск выигрыша в строках
    for (const auto& row : board) {
        if (std::all_of(row.begin(), row.end(), [playerSymbol](char cell) { return cell == playerSymbol; })) {
            return true;
        }
    }

    // Поиск выигрыша в столбцах
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        std::vector<char> column;
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            column.push_back(board[j][i]);
        }
        if (std::all_of(column.begin(), column.end(), [playerSymbol](char cell) { return cell == playerSymbol; })) {
            return true;
        }
    }

    // Поиск выигрыша в диагоналях
    std::vector<char> diagonal1;
    std::vector<char> diagonal2;
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        diagonal1.push_back(board[i][i]);
        diagonal2.push_back(board[i][BOARD_SIZE - 1 - i]);
    }
    if (std::all_of(diagonal1.begin(), diagonal1.end(), [playerSymbol](char cell) { return cell == playerSymbol; }) ||
        std::all_of(diagonal2.begin(), diagonal2.end(), [playerSymbol](char cell) { return cell == playerSymbol; })) {
        return true;
    }

    return false;
}