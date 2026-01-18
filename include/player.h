
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
  public:
    struct PlayerOpts
    {
        std::string name;
        int x{0};
        int y{0};
        int speed{1};
        bool isHostile{false};
    };
    Player(PlayerOpts &opts);
    Player();

    std::string m_name;
    int m_x;
    int m_y;
    int m_speed;
    bool m_isHostile;

    int getX();
    int getY();
    std::string getName();

  private:
    // ...
};

#endif
