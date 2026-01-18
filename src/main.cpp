#include "board.h"

#include <iostream>

int main()
{
    Player::PlayerOpts playerOpts = {"Bobby", 0, 0, 1, false};
    Player player(playerOpts);

    Player::PlayerOpts opponentOpts = {"Michel", 19, 9, 1, false};
    Player opponent(opponentOpts);

    Board::BoardOpts boardOpts = {20, 10, player, opponent};
    Board board(boardOpts);

    board.prettyPrint();
    board.nextStep();
    std::cout << '\n';
    board.prettyPrint();

    return 0;
}
