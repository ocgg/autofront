#ifndef BOARD_H
#define BOARD_H

#include "colors.h"
#include "player.h"

#include <optional>
#include <string>
#include <vector>

class Board
{
  public:
    struct BoardOpts
    {
        int width{0};
        int height{0};
        Player &player;
        Player &opponent;
    };
    // Constructor
    Board(BoardOpts &opts);

    void nextStep();
    // (for debugging) displays the board in terminal
    void prettyPrint();

  private:
    struct Cell
    {
        std::string color{"background"};
        std::string escapeCode{colors::black};
        std::optional<Player> owner;
    };

    // 2-dimensional array of Cells (vector of vectors of Cells)
    std::vector<std::vector<Cell>> m_grid;
    int m_width{0};
    int m_height{0};
    Player &m_player;
    Player &m_opponent;

    void makeGrid();
};

#endif
