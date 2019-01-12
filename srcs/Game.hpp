#ifndef GAME_HPP
#define GAME_HPP

#include "Background.hpp"
#include "Enemy.hpp"
#include "Hurler.hpp"
#include "Missile.hpp"
#include "Ship.hpp"
#include "ft_retro.hpp"
#include <cstring>

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
  unsigned int _turn;

  void _handleShip(int);
  void _handleBackground();
  void _addNewBackGroundElem(int, int);

  Game(Game const &src);
  Game &operator=(Game const &src);

public:
  Game();
  virtual ~Game();

  char *update(int input);
};

#endif // GAME_HPP