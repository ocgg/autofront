#include "board.h"

#include "colors.h"

#include <iostream>

// Constructor
Board::Board(BoardOpts &opts) : m_player(opts.player), m_opponent(opts.opponent)
{
    m_width = opts.width;
    m_height = opts.height;
    m_player = opts.player;
    m_opponent = opts.opponent;
    makeGrid();
}

void Board::makeGrid()
{
    // resize grid with width & height
    m_grid.resize(m_height);
    for (auto &row : m_grid)
    {
        row.resize(m_width);
    }

    // Place player
    Cell &playerCell = m_grid[m_player.getY()][m_player.getX()];
    playerCell.escapeCode = colors::green;
    playerCell.owner = m_player;
    // Place opponent
    Cell &opCell = m_grid[m_opponent.getY()][m_opponent.getX()];
    opCell.escapeCode = colors::red;
    opCell.owner = m_opponent;
}

void Board::nextStep()
{
    // get player neighbors
    std::vector<Cell*> playerNeighbors;

    size_t y = m_player.getY();
    size_t x = m_player.getX();

    if (y)
    {
        playerNeighbors.push_back(&m_grid[y - 1][x]);
    }
    if (y < m_grid.size())
    {
        playerNeighbors.push_back(&m_grid[y + 1][x]);
    }
    if (x)
    {
        playerNeighbors.push_back(&m_grid[y][x - 1]);
    }
    if (x < m_grid[0].size())
    {
        playerNeighbors.push_back(&m_grid[y][x + 1]);
    }

    // extend to neighbors
    for (Cell* cell : playerNeighbors)
    {
        cell->owner = m_player;
        cell->escapeCode = colors::green;
        std::cout << cell->owner->getName();
    }
}

void Board::prettyPrint()
{
    for (auto &row : m_grid)
    {
        for (auto &cell : row)
        {
            std::cout << cell.escapeCode;
        }
        std::cout << '\n';
    }
}
