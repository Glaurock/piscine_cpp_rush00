#ifndef SHIP_HPP
#define SHIP_HPP

#include <ncurses.h>
#include "AGameEntity.hpp"
#include "Missile.hpp"
#include "ft_retro.hpp"

#include <fstream>

class Ship : public AGameEntity {

private:
    Ship(Ship const & src);
    Ship & operator=(Ship const & src);

public:
    Ship();
    virtual ~Ship();

    void move();
    void move(int dir);
    Missile * fireMissile(void);
};

#endif // SHIP_HPP