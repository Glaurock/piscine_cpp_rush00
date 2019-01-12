#ifndef SHIP_HPP
#define SHIP_HPP

#include "AGameEntity.hpp"
#include "Missile.hpp"
#include "ft_retro.hpp"

class Ship : public AGameEntity {

private:
    Ship(Ship const & src);
    Ship & operator=(Ship const & src);

public:
    Ship();
    virtual ~Ship();

    void move();
    Missile *fireMissile(void);
};

#endif // SHIP_HPP