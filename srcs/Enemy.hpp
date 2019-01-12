#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AGameEntity.hpp"

class Game;

class Enemy : public AGameEntity {

protected:
  int _direction;

private:
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &src);
  int _hp;

public:
  Enemy(int x = 5, int y = 3, int velocity = 2, char type = 'T', int hp = 1);
  virtual ~Enemy();

  virtual void move(int); // can be overidden for more subtle patterns
  virtual void move(char *arena);
  bool collided(void);
  virtual void draw(Game *); // ONLY IMPLEMENTED IN "BOSS" FOR NOW
};

#endif // ENEMY_HPP