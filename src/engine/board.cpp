#include "board.h"

#include "colors.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

// Constructor
Board::Board(BoardOpts &opts)
    : m_player(opts.player), m_opponent(opts.opponent), m_finished(false), m_winner(nullptr)
{
    m_width = opts.width;
    m_height = opts.height;
    makeGrid();
}

void Board::makeGrid()
{
    // resize grid with width & height
    m_grid.resize(m_height);
    for (auto &row : m_grid) row.resize(m_width);

    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; size_t(x) < m_grid[0].size(); ++x)
        {
            Cell *cell = &m_grid[y][x];
            cell->setX(x);
            cell->setY(y);
            cell->setNorth(y > 0 ? &m_grid[y - 1][x] : nullptr);
            cell->setSouth(y < m_height - 1 ? &m_grid[y + 1][x] : nullptr);
            cell->setEast(x < m_width - 1 ? &m_grid[y][x + 1] : nullptr);
            cell->setWest(x > 0 ? &m_grid[y][x - 1] : nullptr);
        }
    }

    // Place players
    place(m_player);
    place(m_opponent);
}

void Board::place(Player &player)
{
    Cell *cell = &m_grid[player.getY()][player.getX()];
    cell->setOwner(&player);
    player.addCell(cell);
}

void Board::nextStep()
{
    // Process both players' turns with probabilistic conquest
    processPlayerTurn(m_player);
    processPlayerTurn(m_opponent);
    // check entire board for surrounded cells
    for (auto &row : m_grid)
    {
        for (auto &cell : row)
            if (cell.isSurrounded()) cell.setOwner(cell.m_surroundedBy);
    }
    checkVictory();
}

void Board::processPlayerTurn(Player &player)
{
    // Find all boundary cells for this player
    std::vector<Cell *> boundaries = getBoundaryCells(player);

    // Try to conquer each boundary cell
    for (Cell *cell : boundaries)
    {
        if (player.rollExpansion()) cell->setOwner(&player);
    }

    // Rebuild player's cell list from the grid
    rebuildPlayerCells(player);
}

void Board::rebuildPlayerCells(Player &player)
{
    std::vector<Cell *> newCells;

    // Scan the entire grid for cells owned by this player
    for (auto &row : m_grid)
    {
        for (auto &cell : row)
        {
            Player *owner = cell.getOwner();
            if (owner == &player)
            {
                newCells.push_back(&cell);
            }
        }
    }

    // Update player's cell list (Board is friend of Player)
    player.m_cells = newCells;
}
std::vector<Cell *> Board::getBoundaryCells(Player &player)
{
    std::set<Cell *> boundarySet;
    std::vector<Cell *> playerCells = player.getCells();

    for (Cell *cell : playerCells)
    {
        int x{cell->getX()};
        int y{cell->getY()};
        // North
        if (y > 0)
        {
            Cell *north = &m_grid[y - 1][x];
            if (north->getOwner() != &player) boundarySet.insert(north);
        }
        // South
        if (size_t(y) < m_grid.size() - 1)
        {
            Cell *south = &m_grid[y + 1][x];
            if (south->getOwner() != &player) boundarySet.insert(south);
        }
        // West
        if (x > 0)
        {
            Cell *west = &m_grid[y][x - 1];
            if (west->getOwner() != &player) boundarySet.insert(west);
        }
        // East
        if (size_t(x) < m_grid[0].size() - 1)
        {
            Cell *east = &m_grid[y][x + 1];
            if (east->getOwner() != &player) boundarySet.insert(east);
        }
    }
    // Convert set to vector
    return std::vector<Cell *>(boundarySet.begin(), boundarySet.end());
}

void Board::prettyPrint()
{
    for (auto &row : m_grid)
    {
        for (auto &cell : row)
        {
            if (cell.getOwner())
            {
                std::cout << cell.getOwner()->getColor();
            }
            else
            {
                std::cout << colors::black;
            }
        }
        std::cout << '\n';
    }
}

void Board::checkVictory()
{
    Player *firstCellOwner = m_grid[0][0].getOwner();
    for (auto &row : m_grid)
    {
        for (Cell cell : row)
        {
            if (cell.getOwner() != firstCellOwner) return;
        }
    }
    m_finished = true;
    m_winner = firstCellOwner;
}

Player* Board::getWinner() {
    return m_winner;
}

bool Board::gameIsFinished() {
    return m_finished;
}
