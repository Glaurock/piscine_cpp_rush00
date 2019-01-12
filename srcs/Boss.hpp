#ifndef BOSS_HPP
# define BOSS_HPP

# include "Enemy.hpp"
# include "AGameEntity.hpp"
# include "Game.hpp"

class Game;

class Boss : public Enemy {

private:
    Boss(Boss const & src);
    Boss & operator=(Boss const & src);
    int _size;

    Enemy ** _surface;

public:
    Boss();
    virtual ~Boss();

    int getSize() const;

    void draw(Game * game);
    static int boss1[6];  
    virtual void move(int);    
};

# endif // BOSS_HPP