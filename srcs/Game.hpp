#ifndef GAME_HPP
#define GAME_HPP

#include "Background.hpp"
#include "Enemy.hpp"
#include "Hurler.hpp"
#include "Missile.hpp"
#include "Ship.hpp"
#include "Slicer.hpp"

#include <cstring>

// remove this later
#include <fstream>
#include <string>

class Background;

class Game
{

private:
  char _arena[ARENA_WIDTH * ARENA_HEIGHT];
  Ship *_ship;
  Missile *_missiles[MAX_MISSILES];
  Enemy *_enemies[MAX_ENEMIES];
  Background *_backgrounds[MAX_BACKGROUNDS];
  unsigned int _turn;
  unsigned int _score;

  void _handleShip(int);
  void _handleBackground();
  void _handleMissiles();
  void _handleEnemies();
  Enemy * _enemySpawner();

  Game(Game const &src);
  Game &operator=(Game const &src);

public:
  Game();
  virtual ~Game();

  char *update(int input);
  void addNewBackGroundElem(int, int);
};

#endif // GAME_HPP