#include "Hurler.hpp"

// Hurler::Hurler() {}
Hurler::Hurler(int x, int y, int velocity, char type) : Enemy(x, y, velocity, type) {}

Hurler::Hurler(Hurler const &src) {}

Hurler::~Hurler() {}

void Hurler::draw(Game *game) {}

int Hurler::move(int turn, char *arena)
{
  int velocity = this->getVelocity();
  int retval = 0;

  if (turn % velocity == 0)
  {
    this->_x += 1;
    this->_y += 2;
  }
  return retval;
}

// Hurler & Hurler::operator=(Hurler const & src) {}