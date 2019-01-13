#include "Hurler.hpp"

// Hurler::Hurler() {}
Hurler::Hurler(int x, int y, int velocity, char type) : Enemy(x, y, velocity, type, 1000) {}

Hurler::~Hurler() {}

int Hurler::move(int turn, char *arena)
{
  int velocity = this->getVelocity();

  if (turn % velocity == 0)
  {
    this->_x += 1;
    this->_y += 2;
  }
  if (arena[0])
    return 0;
  return 0;
}

// Hurler & Hurler::operator=(Hurler const & src) {}