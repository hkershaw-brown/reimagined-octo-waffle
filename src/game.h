#ifndef GAME_H
#define GAME_H

#ifdef __cplusplus
extern "C" {
#endif

void resetGame();
bool makeMove(int row, int col);
const char* getBoard();
char getCurrentPlayer();
bool isGameOver();

#ifdef __cplusplus
}
#endif

#endif // GAME_H