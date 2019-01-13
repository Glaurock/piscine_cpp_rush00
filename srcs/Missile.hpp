#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "AGameEntity.hpp"

class Missile : public AGameEntity
{

private:
  Missile(Missile const &src);
  Missile &operator=(Missile const &src);
  Missile();
  int _dir;

public:
  Missile(int x, int y, int velocity = 1, char type = '|', int dir = -1); // x/y refer to ship
  virtual ~Missile();
  int move(int, char *arena); // can be overidden for more subtle patterns
  static const char _type;
};

#endif // MISSILE_HPP
