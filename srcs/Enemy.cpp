#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int velocity, char type)
    : AGameEntity(x, y, velocity, type), _direction(1)
{
  return;
}

Enemy::Enemy(Enemy const &src) {}

Enemy::~Enemy()
{
} // we could display a '*' for one frame where an enemy was killed

Enemy &Enemy::operator=(Enemy const &src) {}

int Enemy::getDirection(void)
{
  return this->_direction;
}

void Enemy::setDirection(int sign)
{
  this->_direction *= sign;
}

void Enemy::setX(int x)
{
  this->_x = x;
}

void Enemy::setY(int y)
{
  this->_y = y;
}

void Enemy::bounce()
{
  this->_x += (2 * this->_direction) % ARENA_WIDTH;
}

int Enemy::checkBorder(char *arena)
{
  int next_coordinate = this->_y * ARENA_WIDTH + (this->_x + this->_direction);

  if ((arena[next_coordinate % ARENA_SIZE] == '*') || ((this->_x + this->_direction) > ARENA_WIDTH - MAX_BACKGROUNDS_SIZE + 1 ||
                                                       (this->_x + this->_direction) < MAX_BACKGROUNDS_SIZE + 1))
  {
    this->_direction *= -1;
    this->bounce();
    return 1;
  }
  return 0;
}

int Enemy::move(int turn, char *arena)
{
  if (turn % this->_velocity == 0)
  {
    this->_x += this->_direction;
  }
  if (turn % 15 == 0)
  {
    this->_y += 1;
  }
  return 0;
}

int Enemy::move(int turn) // safest method for BG check
{
  int velocity = this->getVelocity();

  if (turn % velocity == 0)
    return 0;
  return 0; // stay where you are
}

bool Enemy::collided(void)
{
  return true;
}

Missile *Enemy::fireMissile(void)
{
  return new Missile(this->getXCoordinate(), this->getYCoordinate() + 1, 1, 'Y', 1);
}

bool Enemy::checkOutOfBounds(void)
{
  if (this->getCoordinate() > (ARENA_HEIGHT * ARENA_WIDTH) - 1)
    return true;
  return false;
}