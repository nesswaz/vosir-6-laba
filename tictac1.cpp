#include <iostream>
using namespace std;

const int SIZE = 3;

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
        }
    }
}

bool isValidMove(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

void makeMove(char board[SIZE][SIZE], char player, int row, int col) {
    if (isValidMove(board, row, col)) {
        board[row][col] = player;
    }
}

bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}

bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    bool gameOver = false;
    
    initializeBoard(board);
    
    while (!gameOver) {
        displayBoard(board);
        
        int row, col;
        cin >> row >> col;
        
        makeMove(board, currentPlayer, row, col);
        
        if (checkWin(board, currentPlayer)) {
            cout << currentPlayer;
            gameOver = true;
        } else if (checkDraw(board)) {
            cout << "D";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    
    return 0;
}
