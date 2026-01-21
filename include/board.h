#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "player.h"

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
    // Returns all boundary cells (neighbors of player's cells that don't belong to player, without
    // duplicates)
    std::vector<Cell *> getBoundaryCells(Player &player);

  private:
    // 2-dimensional array of Cells (vector of vectors of Cells)
    std::vector<std::vector<Cell>> m_grid;
    int m_width{0};
    int m_height{0};
    Player &m_player;
    Player &m_opponent;

    void makeGrid();
    void place(Player &player);
    // Process one player's turn with probabilistic conquest
    void processPlayerTurn(Player &player);
    // Rebuild player's cell list from the grid
    void rebuildPlayerCells(Player &player);
    
};

#endif
