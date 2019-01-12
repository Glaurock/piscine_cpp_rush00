#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "AGameEntity.hpp"

class Missile : public AGameEntity
{

  private:
    Missile(Missile const &src);
    Missile &operator=(Missile const &src);

  public:
    Missile();
    virtual ~Missile();
    bool move(char *arena); // can be overidden for more subtle patterns
};

#endif // MISSILE_HPP