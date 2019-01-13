
#include "AGameEntity.hpp"

AGameEntity::AGameEntity(void) {}

AGameEntity::AGameEntity(int x, int y, int velocity, char type)
    : _x(x), _y(y), _velocity(velocity), _type(type)
{
  return;
}

AGameEntity::AGameEntity(AGameEntity const &src)
{
  *this = src;
  return;
}

AGameEntity::~AGameEntity(void) {}

AGameEntity &AGameEntity::operator=(AGameEntity const &rhs)
{
  this->_x = rhs.getXCoordinate();
  this->_y = rhs.getYCoordinate();
  this->_velocity = rhs.getVelocity();
  this->_type = rhs.getType();

  return *this;
}

int AGameEntity::getCoordinate(void) const { return ((this->_y * ARENA_WIDTH) + this->_x); }

int AGameEntity::getYCoordinate(void) const { return this->_y; }

int AGameEntity::getXCoordinate(void) const { return this->_x; }

int AGameEntity::getVelocity(void) const { return this->_velocity; }

char AGameEntity::getType(void) const { return this->_type; }

void AGameEntity::draw(char (&arena)[ARENA_SIZE])
{
  arena[this->getCoordinate()] = this->getType();
}
