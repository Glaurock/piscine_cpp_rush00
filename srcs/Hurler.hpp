#ifndef HURLER_HPP
#define HURLER_HPP

#include "Enemy.hpp"

class Game;

class Hurler : public Enemy
{

  private:
    Hurler(Hurler const &src);
    Hurler &operator=(Hurler const &src);

  public:
    Hurler(int x = 1, int y = 1, int velocity = 1, char type = 'H');
    virtual ~Hurler();
    virtual int move(int, char *arena); // can be overidden for more subtle patterns
    virtual void draw(Game *);
};

#endif // HURLER_HPP