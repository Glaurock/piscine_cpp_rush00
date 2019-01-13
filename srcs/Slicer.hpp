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
  Slicer(int x = 1, int y = 1, int velocity = 1, char type = 'K');
  virtual ~Slicer();
  virtual int move(int, char *arena); // can be overidden for more subtle patterns
  virtual void draw(Game *);
};

#endif // SLICER_HPP