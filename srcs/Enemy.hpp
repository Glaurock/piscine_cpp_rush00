#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AGameEntity.hpp"
#include "Missile.hpp"

class Enemy : public AGameEntity
{

protected:
  int _direction;

private:
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &src);
  int _hp;

public:
  Enemy(int x = 10, int y = 3, int velocity = 2, char type = 'T');
  virtual ~Enemy();

  virtual int move(int, char *arena); // can be overidden for more subtle patterns
  virtual int move(int);
  virtual bool collided(void);
  Missile *fireMissile(void);
  int getDirection(void);
  void setDirection(int sign);
  void setX(int x);
  void bounce();
  virtual int checkBorder(char *arena);
  // virtual void draw(char (& arena)[ARENA_SIZE]);
};

#endif // ENEMY_HPP