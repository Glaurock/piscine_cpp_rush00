#include "Boss.hpp"

Boss::Boss() : _hp(100)
{
  this->_velocity = 2;
  this->_type = 'o';
  this->_direction = 1;
  this->_size = sizeof(Boss::boss1) / sizeof(int);
  this->_surface = new Enemy *[this->_size]; /* Leaks here I think */
  for (int i = 0; i < this->_size; i++)
  {
    this->_surface[i] = new Enemy(Boss::boss1[i] % ARENA_WIDTH + 1,
                                  Boss::boss1[i] / ARENA_WIDTH + 1, 2, 1);
  }
}

Boss::~Boss()
{
  // destruct game objects
}

void Boss::draw(char (&arena)[ARENA_SIZE])
{
  for (int i = 0; i < this->_size; i++)
  {
    arena[this->_surface[i]->getCoordinate()] = this->_type;
  }
}

int Boss::move(int turn, char *arena)
{
  int direction = 0;
  int sign = this->_surface[0]->getDirection();

  for (int i = 0; i < this->_size; i++)
  {
    direction = this->_surface[i]->move(turn, arena); // care when we will remove Enemy move function

    // if (direction)
    // {
    //   this->_surface[i]->resetYCollision();
    //   direction = 0;
  }
  // }
}

int Boss::getSize() const { return this->_size; }

char Boss::getCollision(char *arena)
{
  char worst_collision = 0;

  for (int i = 0; i < this->_size; i++)
  {
    if (arena[(this->_surface[i]->getCoordinate()) % ARENA_SIZE] == 'S')
      return 'S';
    if (arena[(this->_surface[i]->getCoordinate()) % ARENA_SIZE] != ' ')
      if (worst_collision != '|')
        worst_collision = arena[(this->_surface[i]->getCoordinate()) % ARENA_SIZE];
  }
  if (worst_collision == '*' || worst_collision == 'Y' || worst_collision == 'o')
    return 0;
  return worst_collision;
}

bool Boss::collided(void)
{
  this->_hp -= 1;
  if (this->_hp == 0)
  {
    for (int i = 0; i < this->_size; i++)
    {
      delete this->_surface[i];
      this->_surface[i] = NULL;
      return true;
    }
  }
  return false;
}

bool Boss::checkOutOfBounds(void)
{
  for (int i = 0; i < this->_size; i++)
  {
    if (this->_surface[i]->getCoordinate() > (ARENA_HEIGHT * ARENA_WIDTH) - 1)
      return true;
  }
  return false;
}

int Boss::boss1[] = {41 + ARENA_WIDTH, 42 + ARENA_WIDTH,
                     41 + (2 * ARENA_WIDTH),
                     42 + (2 * ARENA_WIDTH),
                     40 + (3 * ARENA_WIDTH), 43 + (3 * ARENA_WIDTH)};
