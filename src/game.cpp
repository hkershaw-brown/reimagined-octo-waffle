#include "game.h"
#include <iostream>
#include <string>
#include <cstring>

extern "C" {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameOver = false;

    void resetGame() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
        currentPlayer = 'X';
        gameOver = false;
    }

    bool makeMove(int row, int col) {
        if (gameOver) return false;
        if (row < 0 || row > 2 || col < 0 || col > 2) return false;
        if (board[row][col] != ' ') return false;
        board[row][col] = currentPlayer;
        // Check win
        for (int i = 0; i < 3; ++i)
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
                gameOver = true;
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
            gameOver = true;
        // Check draw
        bool full = true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ') full = false;
        if (full && !gameOver) gameOver = true;
        if (!gameOver)
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;
    }

    const char* getBoard() {
        //return "hello from C++";
        static std::string out;
        out.clear();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                out += board[i][j];
                if (j < 2) out += "  | ";
            }
            out += "\r\n";
            if (i < 2) out += "---+---+---\r\n";
        }
        return out.c_str();
        
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }

    bool isGameOver() {
        return gameOver;
    }
}