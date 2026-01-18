#include "player.h"

Player::Player(PlayerOpts &opts)
{
    m_name = opts.name;
    m_x = opts.x;
    m_y = opts.y;
    m_speed = opts.speed;
    m_isHostile = opts.isHostile;
}

std::string Player::getName() {
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
