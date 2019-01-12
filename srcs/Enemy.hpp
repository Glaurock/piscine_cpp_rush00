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
  bool move(char *arena); // can be overidden for more subtle patterns
};

#endif // ENEMY_HPP