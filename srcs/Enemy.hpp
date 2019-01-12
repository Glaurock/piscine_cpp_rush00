#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AGameEntity.hpp"

class Enemy : public AGameEntity
{
  private:
    Enemy(Enemy const &src);
    Enemy &operator=(Enemy const &src);

  public:
    // Enemy();
    Enemy(int x = 1, int y = 1, int velocity = 1, char type = 'H');
    virtual ~Enemy();
    void move(void); // can be overidden for more subtle patterns
    void move(char *arena);
};

#endif // ENEMY_HPP