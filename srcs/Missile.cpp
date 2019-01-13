#include "Missile.hpp"

Missile::Missile(int x, int y, int velocity, char type)
    : AGameEntity(x, y, velocity, type) {}

Missile::Missile(Missile const &src) {}

Missile::~Missile() {}

Missile &Missile::operator=(Missile const &src) {}

int Missile::move(int turn, char *arena)
{
    this->_y--;
    if (this->_y <= 1)
    {
        this->_y = -1;
        this->_x = -1;
    }
    return 0;
}

char const Missile::_type = '|';