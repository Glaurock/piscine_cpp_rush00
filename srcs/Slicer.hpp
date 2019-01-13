#ifndef SLICER_HPP
#define SLICER_HPP

#include "Enemy.hpp"

class Game;

class Slicer : public Enemy
{

private:
  Slicer(Slicer const &src);
  Slicer &operator=(Slicer const &src);

public:
  Slicer(int x = 10, int y = 10, int velocity = 2, char type = 'K');
  virtual ~Slicer();
  virtual int move(int, char *arena); // can be overidden for more subtle patterns
  virtual void draw(Game *);
};

#endif // SLICER_HPP