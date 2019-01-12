#include "Missile.hpp"

Missile::Missile() {}

Missile::Missile(Missile const &src) {}

Missile::~Missile() {}

Missile &Missile::operator=(Missile const &src) {}

bool Missile::move(char *arena) {
  int prevY = this->getYCoordinate(); // will just go forward for now
  this->_y += this->_velocity;

  if (arena[this->_x * this->_y] != ' ') // case not empty, we hit something
  {
    // solve collision somehow
    return false;
  }
  arena[this->_x * this->_y] = this->getType(); // update board
  arena[this->_x * prevY] = ' ';                // emptying last occupied case
  return true;
}