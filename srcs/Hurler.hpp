#ifndef HURLER_HPP
# define HURLER_HPP

# include "Enemy.hpp"

class Hurler : public Enemy {

private:

    Hurler(Hurler const & src);
    Hurler & operator=(Hurler const & src);

public:
    Hurler(int x = 1, int y = 1, int velocity = 1, char type = 'H');
    virtual ~Hurler();
    virtual void move(int); // can be overidden for more subtle patterns
};

# endif // HURLER_HPP