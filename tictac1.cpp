#include <iostream>
#include "windows.h"

using namespace std;

const int SIZE_BOARD = 3;

void initializeBoard(char board[SIZE_BOARD][SIZE_BOARD]) {
    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE_BOARD][SIZE_BOARD]) {
    cout << "\n   | 1 | 2 | 3 |" << endl;
    cout << "----------------" << endl;
    for (int i = 0; i < SIZE_BOARD; i++) {
        cout << " " << i + 1 << " | ";
        for (int j = 0; j < SIZE_BOARD; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "----------------" << endl;
    }
}

bool isValidMove(char board[SIZE_BOARD][SIZE_BOARD], int row, int col) {
    return (row >= 0 && row < SIZE_BOARD && col >= 0 && col < SIZE_BOARD && board[row][col] == ' ');
}

void makeMove(char board[SIZE_BOARD][SIZE_BOARD], char player) {
    int row, col;

    while (true) {
        cout << "\nИгрок " << player << ", ваш ход!" << endl;
        cout << "Введите строку (1-3): ";
        cin >> row;
        cout << "Введите столбец (1-3): ";
        cin >> col;

        row--; col--;

        if (isValidMove(board, row, col)) {
            board[row][col] = player;
            break;
        } else {
            cout << "Некорректный ход! Попробуйте еще раз." << endl;
        }
    }
}

bool checkWin(char board[SIZE_BOARD][SIZE_BOARD], char player) {
    for (int i = 0; i < SIZE_BOARD; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

bool checkDraw(char board[SIZE_BOARD][SIZE_BOARD]) {
    for (int i = 0; i < SIZE_BOARD; i++) {
        for (int j = 0; j < SIZE_BOARD; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char board[SIZE_BOARD][SIZE_BOARD];
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "=== КРЕСТИКИ-НОЛИКИ ===" << endl;
    cout << "Игрок 1: X, Игрок 2: O" << endl;

    initializeBoard(board);

    while (!gameOver) {
        displayBoard(board);
        makeMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "\n🎉 Игрок " << currentPlayer << " победил!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "\n🤝 Ничья!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "\nСпасибо за игру!" << endl;
    return 0;
}
