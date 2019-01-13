#include "Bonus.hpp"

Bonus::Bonus(int x, int y, int velocity, char type): AGameEntity(x, y, velocity, type) {}

// Bonus::Bonus(Bonus const & src) {}

Bonus::~Bonus() {}

// Bonus & Bonus::operator=(Bonus const & src) {}

int Bonus::move(int, char *arena) {
    this->_y++;
}
