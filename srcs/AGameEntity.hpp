#ifndef A_GAME_ENTITY_HPP
#define A_GAME_ENTITY_HPP

#include "ft_retro.hpp"

class AGameEntity {
private:
protected:
  int _x;
  int _y;
  int _velocity;
  char _type;

public:
  AGameEntity(void);
  AGameEntity(int x, int y, int velocity, char type);
  AGameEntity(AGameEntity const &src);
  virtual ~AGameEntity(void);

  AGameEntity &operator=(AGameEntity const &rhs);

  virtual void move(void) = 0;
  int getCoordinate(void) const;
  int getYCoordinate(void) const;
  int getXCoordinate(void) const;
  int getVelocity(void) const;
  char getType(void) const;
  // virtual void collided(void) const = 0;
};

#endif