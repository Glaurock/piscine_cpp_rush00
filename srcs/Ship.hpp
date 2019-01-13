#ifndef SHIP_HPP
#define SHIP_HPP

#include "AGameEntity.hpp"
#include "Missile.hpp"
#include "ft_retro.hpp"
#include <ncurses.h>

#include <fstream>

class Ship : public AGameEntity
{

private:
  Ship(Ship const &src);
  Ship &operator=(Ship const &src);
  int _lives;

public:
  Ship();
  virtual ~Ship();

  int getLives(void) const;
  int move(int dir, char *arena);
  Missile *fireMissile(void);
  void collided(void);
  void gainBonus();
};

#endif // SHIP_HPP