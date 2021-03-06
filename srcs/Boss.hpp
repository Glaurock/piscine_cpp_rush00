#ifndef BOSS_HPP
#define BOSS_HPP

#include "Enemy.hpp"
#include "AGameEntity.hpp"

class Boss : public Enemy
{

private:
  Boss(Boss const &src);
  Boss &operator=(Boss const &src);
  int _size;
  int _hp;
  int _value;

  Enemy *_surface[6];

public:
  Boss();
  virtual ~Boss();

  int getSize() const;

  void draw(char (&arena)[ARENA_SIZE]);
  virtual int move(int, char *arena);
  virtual char getCollision(char *arena);
  virtual bool collided(void);
  virtual bool checkOutOfBounds(void);
  virtual int checkBorder(char *arena);
  virtual int getXCoordinate(void) const;
  virtual int getYCoordinate(void) const;
  static int boss1[6];
};

#endif // BOSS_HPP