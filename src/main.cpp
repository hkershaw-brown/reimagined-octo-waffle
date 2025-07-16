#include <iostream>
#include "game.h"

int main() {
    Game game;
    game.start();

    while (!game.gameOver) {
        game.render();

        int row, col;
        char player;
        std::cout << "Enter row (0-2): ";
        std::cin >> row;
        std::cout << "Enter column (0-2): ";
        std::cin >> col;
 
        if (game.makeMove(row, col)) {
            std::cout << "Move accepted.\n";
        } else {
            std::cout << "Invalid move. Try again.\n";
            continue; // Ask again
        }

        game.render();
        game.update();
    }

    return 0;
}