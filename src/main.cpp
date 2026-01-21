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

    Player::PlayerOpts playerOpts = {"Bobby", 0, 0, 1, false, colors::green, 4};
    Player player(playerOpts);

    Player::PlayerOpts opponentOpts = {"Michel", 99, 39, 1, false, colors::red, 1};
    Player opponent(opponentOpts);

    Board::BoardOpts boardOpts = {100, 40, player, opponent};
    Board board(boardOpts);

    board.prettyPrint();

    // Board starts at line 1 (top of terminal)
    int boardStartLine = 1;

    // Hide cursor for smooth animation
    std::cout << "\x1b[?25l";

    while (true)
    {
        // Position cursor to board start
        std::cout << "\x1b[" << boardStartLine << ";1H";

        // Clear only the board area without scrolling
        for (int j = 0; j < boardOpts.height; j++)
        {
            std::cout << "\x1b[K"; // Clear current line
            if (j < boardOpts.height - 1)
            {
                std::cout << "\x1b[1B"; // Move down one line (no newline)
            }
        }

        // Position cursor back to board start and display new board
        std::cout << "\x1b[" << boardStartLine << ";1H";
        board.nextStep();
        board.prettyPrint();

        if (board.gameIsFinished()) break;

        // Wait 50ms for smooth animation
        usleep(50000);
    }

    // Show cursor again
    std::cout << "\x1b[?25h";

    std::cout << board.getWinner()->getName() << " a gagné !" << '\n';

    return 0;
}
