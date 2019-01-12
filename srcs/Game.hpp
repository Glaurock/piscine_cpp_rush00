#ifndef GAME_HPP
# define GAME_HPP

class Game {

private:
    Game();

    Game(Game const & src);
    Game & operator=(Game const & src);

public:
    virtual ~Game();

};

# endif // GAME_HPP