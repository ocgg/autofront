#include "cell.h"

#include <algorithm>
#include <set>
#include <vector>

// Default constructor
Cell::Cell()
    : m_x(0), m_y(0), m_owner(nullptr), m_north(nullptr), m_south(nullptr), m_east(nullptr),
      m_west(nullptr)
{
}

// Getters and setters
Player *Cell::getOwner() const
{
    return m_owner ? m_owner : nullptr;
}

void Cell::setOwner(Player *owner)
{
    m_owner = owner;
}

const int &Cell::getX() const
{
    return m_x;
}

void Cell::setX(int x)
{
    m_x = x;
}

const int &Cell::getY() const
{
    return m_y;
}

void Cell::setY(int y)
{
    m_y = y;
}

void Cell::setNorth(Cell *cell)
{
    m_north = cell;
}

void Cell::setSouth(Cell *cell)
{
    m_south = cell;
}
void Cell::setEast(Cell *cell)
{
    m_east = cell;
}
void Cell::setWest(Cell *cell)
{
    m_west = cell;
}

bool Cell::isSurrounded()
{
    std::vector<Cell *> neighbors;

    if (m_north) neighbors.push_back(m_north);
    if (m_south) neighbors.push_back(m_south);
    if (m_east)  neighbors.push_back(m_east);
    if (m_west)  neighbors.push_back(m_west);

    return std::all_of(neighbors.begin(), neighbors.end(),
                       [&](Cell *c) { return c->getOwner() != m_owner; });
}
