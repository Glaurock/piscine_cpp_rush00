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

  void move();
  void move(int dir);
  Missile *fireMissile(void);
  void collided(void);
};

#endif // SHIP_HPP