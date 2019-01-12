#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AGameEntity.hpp"

class Enemy : public AGameEntity {
private:
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &src);

public:
  Enemy();
  Enemy(int x = 0, int y = 0, int velocity = 1, char type = 'H');
  virtual ~Enemy();
  void move(char *arena);
};

#endif // ENEMY_HPP