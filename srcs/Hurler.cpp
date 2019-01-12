#include "Hurler.hpp"

// Hurler::Hurler() {}
Hurler::Hurler(int x, int y, int velocity, char type) : Enemy(10, 10, 2, 'H') {}

Hurler::Hurler(Hurler const &src) {}

Hurler::~Hurler() {}

void Hurler::draw(Game * game) {}

void Hurler::move(int turn)
{
  int velocity = this->getVelocity();

  if (turn % velocity == 0) {
    // std::cout << "I MOVED BUT NOT GOOD" << std::endl;
    if ((this->_x + 1) > ARENA_WIDTH - 5 ||
        (this->_x + 1) < 5) //// a border of the window would be reached
    {
      if (this->_direction > 0)
        this->_y += 1;
      else
        this->_y -= 1; // basic enemies only go in one general direction
      this->_direction *= -1;  // edge was reached, reverse direction
    }
    else
      this->_x += 1;
    //   if (this->_y > ARENA_HEIGHT)
    //     delete this;
   
    // this->_y += 2;
    this->_y += 2;
  }
}

// Hurler & Hurler::operator=(Hurler const & src) {}