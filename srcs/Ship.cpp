#include "Ship.hpp"

Ship::Ship()
{
    this->_x = ARENA_WIDTH / 2;
    this->_y = ARENA_HEIGHT - 2;
    this->_type = 'S';
    this->_velocity = 3;
    this->_lives = 3;
}

// Ship::Ship(Ship const & src) {}

Ship::~Ship() {}

int Ship::move(int input, char *arena)
{
    switch (input)
    {
    case KEY_UP:
        this->_y -= this->_velocity / 2;
        break;
    case KEY_DOWN:
        this->_y += this->_velocity / 2;
        break;
    case KEY_LEFT:
        this->_x -= this->_velocity;
        break;
    case KEY_RIGHT:
        this->_x += this->_velocity;
        break;
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
    return 0;
}

Missile *Ship::fireMissile(void) { return new Missile(this->_x, this->_y - 1); }
// Ship & Ship::operator=(Ship const & src) {}

void Ship::collided(void)
{
    this->_lives -= 1;
    // if (this->_lives == 0)
    //     ;           // display game over, etc
    this->_x = ARENA_WIDTH / 2; // respawn at start
    this->_y = ARENA_HEIGHT - 2;
}

int Ship::getLives(void) const { return this->_lives; }