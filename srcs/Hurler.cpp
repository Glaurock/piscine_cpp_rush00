#include "Hurler.hpp"

// Hurler::Hurler() {}
Hurler::Hurler(int x, int y, int velocity, char type): 
    Enemy(10, 10, 2, 'T') {    

}


Hurler::Hurler(Hurler const & src) {}

Hurler::~Hurler() {}

void Hurler::move(void) {
int velocity = this->getVelocity();

  if ((this->_x + velocity) > ARENA_WIDTH ||
      (this->_x + velocity) < 0) // a border of the window would be reached
  {
    if (velocity > 0)
      this->_y += velocity;
    else
      this->_y -= velocity; // basic enemies only go in one general direction
    this->_velocity *= -1;  // edge was reached, reverse direction
  } else
    this->_x += velocity;
  //   if (this->_y > ARENA_HEIGHT)
  //     delete this;
  this->_y += 2;
}


// Hurler & Hurler::operator=(Hurler const & src) {}