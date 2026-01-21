#ifndef PLAYER_H
#define PLAYER_H

#include "cell.h"

#include <string>
#include <vector>

class Board; // Forward declaration for friend class

class Player
{
    friend class Board; // Allow Board to access private members

  public:
    struct PlayerOpts
    {
        std::string name;
        int x{0};
        int y{0};
        int speed{1};
        bool isHostile{false};
        std::string_view color;
        int expansionScore{50}; // 0-100% chance to conquer boundary cells
    };
    Player(PlayerOpts &opts);

    bool rollExpansion();
    int getX();
    int getY();
    std::string_view getColor();
    std::string getName();
    int getExpansionScore();
    void addCell(Cell *cell);
    std::vector<Cell *> getCells();
    void setCells(const std::vector<Cell *> &cells);

  private:
    std::string m_name;
    std::string_view m_color;
    std::vector<Cell *> m_cells;
    int m_x;
    int m_y;
    int m_speed;
    int m_expansionScore;
    bool m_isHostile;
};

#endif
