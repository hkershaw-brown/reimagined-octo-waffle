#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "game.h"

int main() {
    Game game;
    game.start();
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed RNG

    while (!game.gameOver) {
        //game.render();

        int row, col;
        if (game.getCurrentPlayer() == 'X') {
            // Computer (X) picks a random empty cell
            std::vector<std::pair<int, int>> emptyCells;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (game.isCellEmpty(i, j))
                        emptyCells.push_back({i, j});
            if (!emptyCells.empty()) {
                int idx = std::rand() % emptyCells.size();
                row = emptyCells[idx].first;
                col = emptyCells[idx].second;
                std::cout << "Computer (X) chooses: " << row << " " << col << std::endl;
            }
        } else {
            // Human (O) input
            std::cout << "Enter row and column (0-2) for your move: ";
            if (!(std::cin >> row >> col)) {
                std::cout << "Invalid input format. Please enter two numbers separated by a space.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }

        if (game.makeMove(row, col)) {
            std::cout << "Move accepted.\n";
        } else {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        game.update();
        game.render();
    }

    //game.render();
    return 0;
}