#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AGameEntity.hpp"

class Enemy : public AGameEntity {

private:
    Enemy();

    Enemy(Enemy const & src);
    Enemy & operator=(Enemy const & src);

public:
    virtual ~Enemy();

};

# endif // ENEMY_HPP