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
    /* Handle screen size limits */
    if (this->_x <= 1)
        this->_x = 2;
    if (this->_x >= ARENA_WIDTH - 1)
        this->_x = ARENA_WIDTH - 2;
    if (this->_y <= 1)
        this->_y = 2;
    if (this->_y >= ARENA_HEIGHT - 1)
        this->_y = ARENA_HEIGHT - 2;
}

Missile * Ship::fireMissile(void)
{
    return new Missile(this->_x, this->_y + 1);
}

// Ship & Ship::operator=(Ship const & src) {}