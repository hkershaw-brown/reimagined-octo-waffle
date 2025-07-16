#ifndef GAME_H
#define GAME_H

class Game {
public:
    void start();
    void update();
    void render();
    bool makeMove(int row, int col);
    bool gameOver;
    char getCurrentPlayer() const;
    bool isCellEmpty(int row, int col) const;

private:
    // Game state and resources
    bool isRunning;
    char board[3][3]; // Tic-Tac-Toe game
    char currentPlayer; // whose turn it is
    bool checkWin(char player);
    bool isBoardFull();
};

#endif // GAME_H