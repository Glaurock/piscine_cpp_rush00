#include "Slicer.hpp"

// Slicer::Slicer() {}
Slicer::Slicer(int x, int y, int velocity, char type) : Enemy(10, 10, 2, 'K') {}

Slicer::Slicer(Slicer const &src) {}

Slicer::~Slicer() {}

void Slicer::move(void)
{
    int velocity = this->getVelocity();

    if ((this->_x + velocity) > ARENA_WIDTH - 5 ||
        (this->_x + velocity) < 5) // a border of the window would be reached
    {
        if (velocity > 0)
            this->_y += velocity;
        else
            this->_y -= velocity; // basic enemies only go in one general direction
        this->_velocity *= -1;    // edge was reached, reverse direction
    }
    else
        this->_x += velocity;
    //   if (this->_y > ARENA_HEIGHT)
    //     delete this;
    this->_y += 1;
    this->_x += 1;
}

// Slicer & Slicer::operator=(Slicer const & src) {}