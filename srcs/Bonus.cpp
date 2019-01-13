#include "Bonus.hpp"

Bonus::Bonus(int x, int y, int velocity, char type) : AGameEntity(x, y, velocity, type) {}

// Bonus::Bonus(Bonus const & src) {}

Bonus::~Bonus() {}

// Bonus & Bonus::operator=(Bonus const & src) {}

int Bonus::move(int turn, char *arena)
{

    if (turn % this->_velocity == 0)
    {
        this->_y++;
    }
    if (this->_y >= ARENA_HEIGHT) {
        this->_y = -1;
        this->_x = -1;
    }
    if (arena[0])
        return 0;
    return 0;
}
