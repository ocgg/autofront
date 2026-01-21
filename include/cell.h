#ifndef CELL_H
#define CELL_H

#include <string>

// Forward declaration to avoid circular dependency
class Player;

class Cell
{
  public:
    struct CellOpts
    {
        Player *owner;
    };
    // Default constructor
    Cell();

    // Getters and setters
    Player *getOwner() const;
    void setOwner(Player *owner);
    const int &getX() const;
    void setX(int x);
    const int &getY() const;
    void setY(int y);

    void setNorth(Cell *cell);
    void setSouth(Cell *cell);
    void setEast(Cell *cell);
    void setWest(Cell *cell);

    bool isSurrounded();
    Player *m_surroundedBy;

  private:
    int m_x;
    int m_y;
    std::string m_color;
    std::string m_escapeCode;
    Player *m_owner;
    Cell *m_north;
    Cell *m_south;
    Cell *m_east;
    Cell *m_west;
};

#endif
