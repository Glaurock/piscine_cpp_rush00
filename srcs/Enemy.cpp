#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int velocity, char type, int hp)
    : AGameEntity(x, y, velocity, type), _hp(hp), _direction(1)
{
  return;
}

Enemy::Enemy(Enemy const &src) {}

Enemy::~Enemy()
{
} // we could display a '*' for one frame where an enemy was killed

Enemy &Enemy::operator=(Enemy const &src) {}

int Enemy::move(int turn, char *arena)
{
  int velocity = this->getVelocity();
  int retval = 0;

  if (turn % velocity == 0)
  {
    if ((this->_x + this->_direction) > ARENA_WIDTH - MAX_BACKGROUNDS_SIZE + 1 ||
        (this->_x + this->_direction) < MAX_BACKGROUNDS_SIZE + 1) //// a border of the window would be reached
    {
      this->_y += 1;
      this->_direction *= -1; // edge was reached, reverse direction
      retval = 1;
    }
    else if (arena[(this->getXCoordinate()) % ARENA_SIZE] != ' ' && arena[(this->getXCoordinate()) % ARENA_SIZE] != '|')
    {
      this->_direction *= -1;
      this->_x += this->_direction;
      retval = 1;
    }
    else
      this->_x += this->_direction;
  }
  return retval;
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
  this->_hp -= 1;
  if (this->_hp == 0)
    return true; // destroys enemy
  return false;
}