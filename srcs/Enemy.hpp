#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AGameEntity.hpp"

class Enemy : public AGameEntity {
private:
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &src);
  int _hp;

public:
  // Enemy();
  Enemy(int x = 1, int y = 1, int velocity = 1, char type = 'T', int hp = 1);
  virtual ~Enemy();
  virtual void move(void); // can be overidden for more subtle patterns
  virtual void move(char *arena);
  bool collided(void);
};

#endif // ENEMY_HPP