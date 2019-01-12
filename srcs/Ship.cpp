#include "Ship.hpp"

Ship::Ship()
{
    this->_x = ARENA_WIDTH / 2;
    this->_y = ARENA_HEIGHT - 2;
    this->_type = 'S';
    this->_velocity = 2;
    this->_lives = 3;
}

// Ship::Ship(Ship const & src) {}

Ship::~Ship() {}

void Ship::move() {}

void Ship::move(int input)
{
    switch (input)
    {
    case KEY_UP:
        this->_y--;
        break;
    case KEY_DOWN:
        this->_y++;
        break;
    case KEY_LEFT:
        this->_x--;
        break;
    case KEY_RIGHT:
        this->_x++;
        break;
    }
    if (this->_x <= 1)
        this->_x = 2;
    if (this->_x >= ARENA_WIDTH - 1)
        this->_x = ARENA_WIDTH - 2;
    if (this->_y <= 1)
        this->_y = 2;
    if (this->_y >= ARENA_HEIGHT - 1)
        this->_y = ARENA_HEIGHT - 2;
}

Missile *Ship::fireMissile(void)
{
    Missile *shot = new Missile(this->_x, this->_y + 1);
    return shot;
}
// Ship & Ship::operator=(Ship const & src) {}

void Ship::collided(void)
{
    this->_lives -= 1;
    if (this->_lives == 0)
        std::exit(0);           // display game over, etc
    this->_x = ARENA_WIDTH / 2; // respawn at start
    this->_y = ARENA_HEIGHT - 2;
}