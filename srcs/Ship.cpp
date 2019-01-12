#include "Ship.hpp"

Ship::Ship() {
    this->_x = ARENA_WIDTH / 2;
    this->_y = ARENA_HEIGHT / 2;
    this->_type = 'S';
    this->_velocity = 2;
}

// Ship::Ship(Ship const & src) {}

Ship::~Ship() {}

void Ship::move()
{
}

Missile *Ship::fireMissile(void)
{
    Missile *shot = new Missile(this->_x, this->_y + 1);
    return shot;
}
// Ship & Ship::operator=(Ship const & src) {}