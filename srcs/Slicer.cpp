#include "Slicer.hpp"

// Slicer::Slicer() {}
Slicer::Slicer(int x, int y, int velocity, char type) : Enemy(x, y, velocity, type, 1000) {}

Slicer::~Slicer() {}

int Slicer::move(int turn, char *arena)
{
  int velocity = this->getVelocity();

  if (turn % velocity == 0)
  {
    this->_x += 1;
    this->_y += 1;
  }
  if (arena[0])
    return 0;
  return 0;
}

// Slicer & Slicer::operator=(Slicer const & src) {}