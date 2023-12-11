#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

/**
 * @brief Проект для реализации игры "Крестики-нолики" (Tic Tac Toe).
 * @details Этот проект содержит класс TicTacToe для игры в "Крестики-нолики".
 *          Он позволяет управлять игровым полем, ходами игроков и проверкой на выигрыш.
 * @author Efremov Nikita
 * @date 2023
 */

/// Размер игровой доски (количество строк и столбцов)
constexpr int BOARD_SIZE = 3;
/// Условие победы (количество символов для выигрыша подряд)
constexpr int WINNING_CONDITION = 3;
/// Тип данных для представления игровой доски
using Board = std::vector<std::vector<char>>;

class TicTacToe {
private:
    std::vector<std::vector<char>> board;/**< Игровое поле. */

public:
    /**
     * @brief Конструктор по умолчанию для класса TicTacToe.
     */
    TicTacToe();  
    /**
     * @brief Конструктор копирования для класса TicTacToe.
     * @param other Другой объект класса TicTacToe для копирования.
     */
    TicTacToe(const TicTacToe& other);  
    /**
     * @brief Оператор присваивания для класса TicTacToe.
     * @param other Другой объект класса TicTacToe для присваивания.
     * @return Ссылка на текущий объект.
     */
    TicTacToe& operator=(const TicTacToe& other);  
    /**
     * @brief Оператор сравнения для класса TicTacToe.
     * @param other Другой объект класса TicTacToe для сравнения.
     * @return true, если объекты равны, в противном случае - false.
     */
    bool operator==(const TicTacToe& other) const;  
    /**
     * @brief Отображает текущее состояние игровой доски.
     */
    void displayBoard() const;  
    /**
    * @brief Проверяет, допустим ли ход в указанную ячейку.
    * @param row Номер строки ячейки.
    * @param col Номер столбца ячейки.
    * @return true, если ход допустим, в противном случае - false.
    */
    bool isValidMove(int row, int col) const; 
    /**
    * @brief Выполняет ход игрока в указанную ячейку.
    * @param row Номер строки ячейки.
    * @param col Номер столбца ячейки.
    * @param currentPlayer Символ текущего игрока ('X' или 'O').
    */
    void makeMove(int row, int col, char currentPlayer); 
    /**
     * @brief Проверяет, выиграл ли игрок, используя заданный символ.
     * @param playerSymbol Символ игрока ('X' или 'O') для проверки победы.
     * @return true, если игрок выиграл, в противном случае - false.
     */
    bool checkWin(char playerSymbol) const; 

};
#endif /* TICTACTOE_H */