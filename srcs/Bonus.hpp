#ifndef BONUS_HPP
# define BONUS_HPP

# include "AGameEntity.hpp"

class Bonus : public AGameEntity {

private:
    Bonus(Bonus const & src);
    Bonus & operator=(Bonus const & src);

public:
    Bonus(int x = ARENA_WIDTH / 2, int y = 3, int velocity = 5, char type = 'B');
    virtual ~Bonus();
    virtual int move(int, char *arena);
};

# endif // BONUS_HPP