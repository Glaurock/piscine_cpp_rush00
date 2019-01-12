#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AGameEntity.hpp"

class Enemy : public AGameEntity {
protected:
  int _direction;

private:
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &src);
  int _hp;

public:
  // Enemy();
  Enemy(int x = 5, int y = 3, int velocity = 2, char type = 'T', int hp = 1);
  virtual ~Enemy();
  virtual void move(int); // can be overidden for more subtle patterns
  virtual void move(char *arena);
  bool collided(void);
};

#endif // ENEMY_HPP