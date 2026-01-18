#include "player.h"

Player::Player()
{
    m_name = "ENV";
    m_x = 0;
    m_y = 0;
    m_speed = 0;
    m_isHostile = 0;
}

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
