#include "Missile.hpp"

Missile::Missile(int x, int y, int velocity, char type, int dir)
    : AGameEntity(x, y, velocity, type), _dir(dir) {}

Missile::Missile(Missile const &src) {}

Missile::~Missile() {}

int Missile::move(int turn, char *arena)
{
    this->_y += this->_dir;
    if (this->_y <= 1 || this->_y >= ARENA_HEIGHT)
    {
        this->_y = -1;
        this->_x = -1;
    }
    return 0;
}

char const Missile::_type = '|';