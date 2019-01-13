#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int velocity, char type, int hp)
    : AGameEntity(x, y, velocity, type), _hp(hp), _direction(1)
{
  // std::cout << this->_type << std::endl;
  // int random;
  // static char list_type[5] = {'H', 'A', 'M', 'U', 'T'};

  // random = 6;
  // // while (random > 5)
  // //   random =
  // //       1 + std::rand() / ((RAND_MAX + 1u) / 5); // needs the
  // ctime/iostream this->_type = list_type[random - 2]; this->_velocity =
  // (random % 2) + 1; this->_hp = 1;
}

Enemy::Enemy(Enemy const &src) {}

Enemy::~Enemy()
{
} // we could display a '*' for one frame where an enemy was killed

Enemy &Enemy::operator=(Enemy const &src) {}

void Enemy::move(int turn)
{
  int velocity = this->getVelocity();

  if (turn % velocity == 0)
  {
    // std::cout << "I MOVED BUT NOT GOOD" << std::endl;
    if ((this->_x + this->_direction) > ARENA_WIDTH - MAX_BACKGROUNDS_SIZE + 1 ||
        (this->_x + this->_direction) <
            MAX_BACKGROUNDS_SIZE + 1) //// a border of the window would be reached
    {
      // if (this->_direction > 0)
      this->_y += 1;
      // else
      // this->_y -= 1; // basic enemies only go in one general direction
      this->_direction *= -1; // edge was reached, reverse direction
    }
    else
      this->_x += this->_direction;
    //   if (this->_y > ARENA_HEIGHT)
    //     delete this;
    // this->_y += 2;
  }
}

void Enemy::draw(Game *game) {}

void Enemy::move(char *arena) // safest method for BG check
{
  int prevX = this->getXCoordinate();
  int prevY = this->getYCoordinate();
  int velocity = this->getVelocity();

  if ((prevX + velocity) > ARENA_WIDTH - 2 ||
      (prevX + velocity) < 0) // a border of the window would be reached
  {
    if (velocity > 0)
      this->_y += velocity;
    else
      this->_y -= velocity; // basic enemies only go in one general direction
    this->_velocity *= -1;  // edge was reached, reverse direction
  }
  else
    this->_x += velocity;
  if (arena[this->_x * this->_y] !=
      ' ') // next case is, at the frame, not empty -> avoid crashing in
           // backgrounds
  {
    this->_x = prevX;
    this->_y = prevY;
    this->_velocity *= -1;
    return; // stay where you are
  }
}

bool Enemy::collided(void)
{
  this->_hp -= 1;
  if (this->_hp == 0)
    return true; // destroys enemy
  return false;
}