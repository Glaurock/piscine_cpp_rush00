#ifndef MISSILE_HPP
# define MISSILE_HPP

# include "AGameEntity.hpp"

class Missile : public AGameEntity {

private:
    Missile();

    Missile(Missile const & src);
    Missile & operator=(Missile const & src);

public:
    virtual ~Missile();

};

# endif // MISSILE_HPP