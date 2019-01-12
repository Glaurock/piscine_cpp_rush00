#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "AGameEntity.hpp"

class Missile : public AGameEntity
{

private:
  Missile(Missile const &src);
  Missile &operator=(Missile const &src);
  Missile();

public:
  Missile(int x, int y, int velocity = 1, char type = '|'); // x/y refer to ship
  virtual ~Missile();
  void move(int); // can be overidden for more subtle patterns
  static const char _type;
};

#endif // MISSILE_HPP
