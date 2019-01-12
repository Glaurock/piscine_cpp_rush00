#include "Ship.hpp"

Ship::Ship(char *arena)
{
    this->_x = 10;
    this->_y = 10;
    this->_type = 'S';
    this->_velocity = 2;
    arena[this->_x * this->_y] = this->_type;
}

// Ship::Ship(Ship const & src) {}

Ship::~Ship() {}

bool Ship::move(char *arena)
{
}

Missile *Ship::fireMissile(void)
{
    Missile *shot = new Missile(this->_x, this->_y + 1);
    return shot;
}
// Ship & Ship::operator=(Ship const & src) {}