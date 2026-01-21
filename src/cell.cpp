#include "cell.h"

// Default constructor
Cell::Cell()
    : m_x(0), m_y(0), m_owner(nullptr)
{
}

// Constructor with options
Cell::Cell(const CellOpts &opts)
    : m_x(0), m_y(0), m_owner(opts.owner)
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

const int &Cell::getX() const {
    return m_x;
}

void Cell::setX(int x) {
    m_x = x;
}

const int &Cell::getY() const {
    return m_y;
}

void Cell::setY(int y) {
    m_y = y;
}
