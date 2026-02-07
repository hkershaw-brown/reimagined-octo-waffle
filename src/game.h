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
    bool makeComputerMove();
 
//private:
    // Game state and resources
    bool isRunning;
    char board[3][3]; // Tic-Tac-Toe game
    char currentPlayer; // whose turn it is
    bool checkWin(char player);
    bool isBoardFull();
};

// C-style wrappers for WebAssembly
#ifdef __cplusplus
extern "C" {
#endif

void* createGame();
void destroyGame(void* game);
bool makeMove(void* game, int row, int col);
const char* getBoard(void* game);
void resetGame(void* game);
bool isGameOver(void* game);
char getCurrentPlayer(void* game);
bool isCellEmpty(void* game, int row, int col);
void renderGame(void* game);
bool makeComputerMove(void* game);
const char* getStatus(void* game);
#ifdef __cplusplus
}
#endif

#endif // GAME_H