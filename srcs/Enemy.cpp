#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int velocity, char type)
    : AGameEntity(x, y, velocity, type)
{
    int random;
    static char list_type[5] = {'H', 'A', 'M', 'U', 'T'};

    random = 6;
    while (random > 5)
        random = 1 + std::rand() / ((RAND_MAX + 1u) / 5); // needs the ctime/iostream
    this->_type = list_type[random - 1];
    this->_velocity = (random % 2) + 1;
}

Enemy::Enemy(Enemy const &src) {}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(Enemy const &src) {}

void Enemy::move(char *arena)
{
    int prevX = this->getXCoordinate();
    int prevY = this->getYCoordinate();
    int velocity = this->getVelocity();

    if (prevX + velocity > MAX_X)
    {
        this->_y += velocity;
        this->_velocity *= -1;
    }
    else
        this->_x += velocity;
    if (arena[this->_x * this->_y] != ' ') // next case is not empty
        return;                            // do something, actually
    arena[this->_x * this->_y] = this->getType();
    arena[prevX * prevY] = ' ';
}