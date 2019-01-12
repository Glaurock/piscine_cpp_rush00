#include "Ship.hpp"

Ship::Ship() {
    this->_x = ARENA_WIDTH / 2;
    this->_y = ARENA_HEIGHT - 2;
    this->_type = 'S';
    this->_velocity = 2;
}

// Ship::Ship(Ship const & src) {}

Ship::~Ship() {}

void Ship::move()
{

}

void Ship::move(int input)
{
    switch (input)
    {
        case KEY_UP:
            this->_y--;
            break ;
        case KEY_DOWN:
            this->_y++;
            break ;
        case KEY_LEFT:
            this->_x--;
            break ;
        case KEY_RIGHT:
            this->_x++;
            break ;
    }
}

Missile *Ship::fireMissile(void)
{
    Missile *shot = new Missile(this->_x, this->_y + 1);
    return shot;
}
// Ship & Ship::operator=(Ship const & src) {}