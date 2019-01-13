#include "Boss.hpp"

Boss::Boss() : _hp(BOSS_HP), _value(5000)
{
  this->_velocity = 2;
  this->_type = 'o';
  this->_direction = 1;
  this->_size = sizeof(Boss::boss1) / sizeof(int);
  for (int i = 0; i < this->_size; i++)
  {
    this->_surface[i] = new Enemy(Boss::boss1[i] % ARENA_WIDTH + 1,
                                  Boss::boss1[i] / ARENA_WIDTH + 1, 2, 1);
  }
}

Boss::~Boss()
{
  for (int i = 0; i < this->_size; i++)
  {
    if (this->_surface[i] != NULL)
      delete this->_surface[i];
    this->_surface[i] = NULL;
  }
}

void Boss::draw(char (&arena)[ARENA_SIZE])
{
  for (int i = 0; i < this->_size; i++)
  {
    arena[(this->_surface[i]->getCoordinate()) % ARENA_SIZE] = this->_type;
  }
}

int Boss::move(int turn, char *arena)
{
  if (this->checkBorder(arena))
  {
    for (int i = 0; i < this->_size; i++)
    {
      this->_surface[i]->setDirection(-1);
      this->_surface[i]->bounce();
    }
  }
  for (int i = 0; i < this->_size; i++)
  {
    this->_surface[i]->move(turn, arena);
  }
  return 0;
}

int Boss::checkBorder(char *arena)
{
  int next_coordinate;
  int x;
  int dir;

  for (int i = 0; i < this->_size; i++)
  {
    x = this->_surface[i]->getXCoordinate();
    dir = this->_surface[i]->getDirection() * 4;
    next_coordinate = this->_surface[i]->getYCoordinate() * ARENA_WIDTH + (x + dir);
    if (arena[next_coordinate % ARENA_SIZE] == '*' || (x + dir == ARENA_WIDTH - MAX_BACKGROUNDS_SIZE))
    {
      return 1;
    }
  }
  return 0;
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
  if (worst_collision != '|') // || worst_collision == 'Y' || worst_collision == 'o')
    return 0;
  return worst_collision;
}

bool Boss::collided(void)
{
  this->_hp -= 1;
  if (this->_hp == 0)
    return true;
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

int Boss::getXCoordinate(void) const
{
  return (this->_surface[0]->getXCoordinate());
}

int Boss::getYCoordinate(void) const
{
  return (this->_surface[0]->getYCoordinate());
}

int Boss::boss1[] = {41 + ARENA_WIDTH, 42 + ARENA_WIDTH,
                     41 + (2 * ARENA_WIDTH),
                     42 + (2 * ARENA_WIDTH),
                     40 + (3 * ARENA_WIDTH), 43 + (3 * ARENA_WIDTH)};
