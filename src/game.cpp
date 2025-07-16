#include "game.h"
#include <iostream>

void Game::start() {
    std::cout << "Game started!" << std::endl;
    // Initialize game state and resources here
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' '; // Initialize Tic-Tac-Toe board
        }
    }
    currentPlayer = 'X'; // Start with player X
    gameOver = false; // Game is not over at the start
}

void Game::update() {
    // Check for a win or draw after each move
    if (checkWin('X')) {
        std::cout << "Player X wins!" << std::endl;
        gameOver = true;
    } else if (checkWin('O')) {
        std::cout << "Player O wins!" << std::endl;
        gameOver = true;
    } else if (isBoardFull()) {
        std::cout << "It's a draw!" << std::endl;
        gameOver = true;
    }
}

bool Game::checkWin(char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Columns
            return true;
        }
    }
    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool Game::isBoardFull() {
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false; // Found an empty cell
        }
    }
    return true; // No empty cells found
}

void Game::render() {
    //std::cout << "Game rendered!" << std::endl;
    // Render game graphics here
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << ' ' << board[i][j] << ' ';
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---+---+---" << std::endl;
    }
}

bool Game::makeMove(int row, int col) {
    // Check if the move is within bounds and the cell is empty
    if (row < 0 || row > 2 || col < 0 || col > 2) return false;
    if (board[row][col] != ' ') return false;

    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    return true;
}

char Game::getCurrentPlayer() const {
    return currentPlayer;
}

bool Game::isCellEmpty(int row, int col) const {
    return board[row][col] == ' ';
}