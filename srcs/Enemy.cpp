#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int velocity, char type)
    : AGameEntity(x, y, velocity, type)
{
    int random;
    static char list_type[5] = {'H', 'A', 'M', 'U', 'T'};

    random = 6;
    while (random > 5)
        random =
            1 + std::rand() / ((RAND_MAX + 1u) / 5); // needs the ctime/iostream
    this->_type = list_type[random - 1];
    this->_velocity = (random % 2) + 1;
}

Enemy::Enemy(Enemy const &src) {}

Enemy::~Enemy()
{
} // we could display a '*' for one frame where an enemy was killed

Enemy &Enemy::operator=(Enemy const &src) {}

bool Enemy::move(char *arena)
{
    int prevX = this->getXCoordinate();
    int prevY = this->getYCoordinate();
    int velocity = this->getVelocity();

    if ((prevX + velocity) > ARENA_WIDTH ||
        (prevX + velocity) < 0) // a border of the window would be reached
    {
        if (velocity > 0)
            this->_y += velocity;
        else
            this->_y -= velocity; // basic enemies only go in one general direction
        this->_velocity *= -1;    // edge was reached, reverse direction
    }
    else
        this->_x += velocity;
    if (arena[this->_x * this->_y] != ' ') // next case is not empty
    {
        this->_x = prevX;
        this->_y = prevY;
        return false; // stay where you are
    }
    arena[this->_x * this->_y] = this->getType(); // update board
    arena[prevX * prevY] = ' ';                   // emptying last occupied case
    return true;
}