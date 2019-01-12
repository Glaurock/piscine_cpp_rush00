#ifndef GAME_HPP
#define GAME_HPP

#include <cstring>
#include "ft_retro.hpp"
#include "Ship.hpp"
#include "Enemy.hpp"
#include "Missile.hpp"
#include "Background.hpp"

// remove this later
#include <fstream>
#include <string>

class Game
{

  private:
    char _arena[ARENA_WIDTH * ARENA_HEIGHT];
    Ship *_ship;
    Missile *_missiles[MAX_MISSILES];
    Enemy *_enemies[MAX_ENEMIES];
    Background *_backgrounds[MAX_BACKGROUNDS];

    Game(Game const &src);
    Game &operator=(Game const &src);

  public:
    Game();
    virtual ~Game();

    char *update();
};

#endif // GAME_HPP