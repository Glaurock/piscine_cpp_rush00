#ifndef BONUS_HPP
# define BONUS_HPP

# include "AGameEntity.hpp"

class Bonus : public AGameEntity {

private:
    Bonus(Bonus const & src);
    Bonus & operator=(Bonus const & src);

public:
    Bonus(int x = 1, int y = 1, int velocity = 1, char type = 'B');
    virtual ~Bonus();
    virtual int move(int, char *arena);
};

# endif // BONUS_HPP