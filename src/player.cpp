#include "player.h"

Player::Player(PlayerOpts &opts)
    : m_name(opts.name), m_color(opts.color), m_x(opts.x), m_y(opts.y), m_speed(opts.speed),
      m_expansionScore(opts.expansionScore), m_isHostile(opts.isHostile)
{
}

std::string Player::getName()
{
    return m_name;
}

int Player::getX()
{
    return m_x;
}
int Player::getY()
{
    return m_y;
}

std::string_view Player::getColor()
{
    return m_color;
}

void Player::addCell(Cell *cell)
{
    m_cells.push_back(cell);
}

std::vector<Cell *> Player::getCells()
{
    return m_cells;
}

int Player::getExpansionScore()
{
    return m_expansionScore;
}

void Player::setCells(const std::vector<Cell *> &cells)
{
    m_cells = cells;
}

bool Player::rollExpansion()
{
    // Roll a random number between 1 and 100
    int roll = (rand() % 100) + 1;
    // Success if roll is less than or equal to the score
    return roll <= m_expansionScore;
}
