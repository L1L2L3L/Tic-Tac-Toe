#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

/**
 * @brief ������ ��� ���������� ���� "��������-������" (Tic Tac Toe).
 * @details ���� ������ �������� ����� TicTacToe ��� ���� � "��������-������".
 *          �� ��������� ��������� ������� �����, ������ ������� � ��������� �� �������.
 * @author Efremov Nikita
 * @date 2023
 */

/// ������ ������� ����� (���������� ����� � ��������)
constexpr int BOARD_SIZE = 3;
/// ������� ������ (���������� �������� ��� �������� ������)
constexpr int WINNING_CONDITION = 3;
/// ��� ������ ��� ������������� ������� �����
using Board = std::vector<std::vector<char>>;

class TicTacToe {
private:
    std::vector<std::vector<char>> board;/**< ������� ����. */

public:
    /**
     * @brief ����������� �� ��������� ��� ������ TicTacToe.
     */
    TicTacToe();  
    /**
     * @brief ����������� ����������� ��� ������ TicTacToe.
     * @param other ������ ������ ������ TicTacToe ��� �����������.
     */
    TicTacToe(const TicTacToe& other);  
    /**
     * @brief �������� ������������ ��� ������ TicTacToe.
     * @param other ������ ������ ������ TicTacToe ��� ������������.
     * @return ������ �� ������� ������.
     */
    TicTacToe& operator=(const TicTacToe& other);  
    /**
     * @brief �������� ��������� ��� ������ TicTacToe.
     * @param other ������ ������ ������ TicTacToe ��� ���������.
     * @return true, ���� ������� �����, � ��������� ������ - false.
     */
    bool operator==(const TicTacToe& other) const;  
    /**
     * @brief ���������� ������� ��������� ������� �����.
     */
    void displayBoard() const;  
    /**
    * @brief ���������, �������� �� ��� � ��������� ������.
    * @param row ����� ������ ������.
    * @param col ����� ������� ������.
    * @return true, ���� ��� ��������, � ��������� ������ - false.
    */
    bool isValidMove(int row, int col) const; 
    /**
    * @brief ��������� ��� ������ � ��������� ������.
    * @param row ����� ������ ������.
    * @param col ����� ������� ������.
    * @param currentPlayer ������ �������� ������ ('X' ��� 'O').
    */
    void makeMove(int row, int col, char currentPlayer); 
    /**
     * @brief ���������, ������� �� �����, ��������� �������� ������.
     * @param playerSymbol ������ ������ ('X' ��� 'O') ��� �������� ������.
     * @return true, ���� ����� �������, � ��������� ������ - false.
     */
    bool checkWin(char playerSymbol) const; 

};
#endif /* TICTACTOE_H */