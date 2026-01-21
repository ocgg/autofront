#include "board.h"
#include "colors.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

int main()
{
    // Initialize random number generator
    srand(time(0));

    Player::PlayerOpts playerOpts = {"Bobby", 0, 0, 1, false, colors::green, 70};
    Player player(playerOpts);

    Player::PlayerOpts opponentOpts = {"Michel", 19, 9, 1, false, colors::red, 30};
    Player opponent(opponentOpts);

    Board::BoardOpts boardOpts = {20, 10, player, opponent};
    Board board(boardOpts);

    board.prettyPrint();

    std::cout << "\nInitial stats:\n";
    std::cout << player.getName() << " cells: " << player.getCells().size()
              << " (expansion: " << player.getExpansionScore() << "%)\n";
    std::cout << opponent.getName() << " cells: " << opponent.getCells().size()
              << " (expansion: " << opponent.getExpansionScore() << "%)\n";

    for (int i = 1; i <= 20; ++i)
    {
        std::cout << "\n=== Turn " << i << " ===\n";
        board.nextStep();
        board.prettyPrint();

        std::cout << player.getName() << " cells: " << player.getCells().size() << "\n";
        std::cout << opponent.getName() << " cells: " << opponent.getCells().size() << "\n";
    }

    return 0;
}
