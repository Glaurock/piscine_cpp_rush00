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
  Enemy(int x = 10, int y = 3, int velocity = 2, char type = 'T', int hp = 1);
  virtual ~Enemy();

  virtual int move(int, char *arena); // can be overidden for more subtle patterns
  virtual int move(int);
  bool collided(void);
  Missile *fireMissile(void);
};

#endif // ENEMY_HPP