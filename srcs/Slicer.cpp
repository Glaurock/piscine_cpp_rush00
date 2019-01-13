#include "Slicer.hpp"

// Slicer::Slicer() {}
Slicer::Slicer(int x, int y, int velocity, char type) : Enemy(x, y, velocity, type) {}

Slicer::Slicer(Slicer const &src) {}

Slicer::~Slicer() {}

void Slicer::draw(Game *game) {}

int Slicer::move(int turn, char *arena)
{
  int velocity = this->getVelocity();
  int retval = 0;
  if (turn % velocity == 0)
  {
    this->_x += 1;
    this->_y += 1;
  }
  return retval;
}

// Slicer & Slicer::operator=(Slicer const & src) {}