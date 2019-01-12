#ifndef SHIP_HPP
# define SHIP_HPP

# include "AGameEntity.hpp"

class Ship : public AGameEntity {

private:

    Ship(Ship const & src);
    Ship & operator=(Ship const & src);

public:
    Ship();
    virtual ~Ship();

};

# endif // SHIP_HPP