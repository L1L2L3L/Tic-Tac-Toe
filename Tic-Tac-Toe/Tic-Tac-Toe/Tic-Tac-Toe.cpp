#include <iostream>

// Размер доски и количество побед
const int BOARD_SIZE = 3;
const int WINNING_CONDITION = 3; 

// Отображения игровой доски
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            std::cout << board[row][col];
            if (col < BOARD_SIZE - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (row < BOARD_SIZE - 1) {
            std::cout << "---------" << std::endl;
        }
    }
}

// Проверка, можно ли сделать ход в указанную ячейку
bool isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    return row >= 1 && row <= BOARD_SIZE && col >= 1 && col <= BOARD_SIZE && board[row - 1][col - 1] == ' ';
}

// Функция хода
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char playerSymbol) {
    board[row - 1][col - 1] = playerSymbol;
}

// Функция проверки победы
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char playerSymbol) {
    // Проверяем горизонтали, вертикали 
    for (int i = 0; i < BOARD_SIZE; ++i) {
        bool winInRow = true;
        bool winInCol = true;
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != playerSymbol) {
                winInRow = false;
            }
            if (board[j][i] != playerSymbol) {
                winInCol = false;
            }
        }
        if (winInRow || winInCol) {
            return true;
        }
    }

    // Проверяем диагонали
    bool winInDiagonal1 = true;
    bool winInDiagonal2 = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][i] != playerSymbol) {
            winInDiagonal1 = false;
        }
        if (board[i][BOARD_SIZE - 1 - i] != playerSymbol) {
            winInDiagonal2 = false;
        }
    }

    return winInDiagonal1 || winInDiagonal2;
}

int main() {
    // Игровое поле
    char board[BOARD_SIZE][BOARD_SIZE]; 
    int playerXWins = 0;
    int playerOWins = 0;
    // Начинает игрок X
    char currentPlayer = 'X'; 

    while (true) {
        // Инициализация доски
        for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                board[row][col] = ' '; // Пустые ячейки
            }
        }

        // Основной цикл
        int moves = 0; // Счетчик ходов
        while (true) {
            // Отображение текущего состояния игровой доски
            displayBoard(board);

            int row, col;
            std::cout << "Player " << currentPlayer << "'s turn. Enter row (1-" << BOARD_SIZE << ") and column (1-" << BOARD_SIZE << "): ";
            std::cin >> row >> col;
            // Если ход допустимый 
            if (isValidMove(board, row, col)) {
                makeMove(board, row, col, currentPlayer);
                moves++;

                if (checkWin(board, currentPlayer)) {
                    std::cout << "Player " << currentPlayer << " win!" << std::endl;
                    if (currentPlayer == 'X') {
                        playerXWins++;
                    }
                    else {
                        playerOWins++;
                    }
                    break; // Завершаем текущую игру
                }
                else if (moves == BOARD_SIZE * BOARD_SIZE) {
                    std::cout << "Draw!" << std::endl;
                    break; // Завершаем текущую игру
                }

                // Смена игрока
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            else {
                //Сообщение об ошибке
                std::cout << "Incorrect move. Try again." << std::endl;
            }
        }

        std::cout << "Count: Player X - " << playerXWins << ", Player O - " << playerOWins << std::endl;

        if (playerXWins == WINNING_CONDITION || playerOWins == WINNING_CONDITION) {
            std::cout << "Game over! Reached best-of-three  " << WINNING_CONDITION << " set." << std::endl;
            break; // Завершаем игру
        }

        char playAgain;
        std::cout << "Want to start a new game? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break; //Завершаем программу
        }
    }

    return 0;
}