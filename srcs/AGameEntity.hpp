#ifndef A_GAME_ENTITY_HPP
#define A_GAME_ENTITY_HPP

#include "ft_retro.hpp"

class AGameEntity
{
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

  virtual int move(int, char *arena) = 0;
  virtual void draw(char (&arena)[ARENA_SIZE]);
  int getCoordinate(void) const;
  virtual int getYCoordinate(void) const;
  void resetYCollision(void);
  virtual int getXCoordinate(void) const;
  int getVelocity(void) const;
  char getType(void) const;
  virtual char getCollision(char *arena);
};

#endif