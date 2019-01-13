#ifndef GAME_HPP
#define GAME_HPP

#include "Background.hpp"
#include "Boss.hpp"
#include "Enemy.hpp"
#include "Hurler.hpp"
#include "Missile.hpp"
#include "Ship.hpp"
#include "Slicer.hpp"
#include "Bonus.hpp"

#include <cstring>

class Background;

class Game
{

private:
  char _arena[ARENA_WIDTH * ARENA_HEIGHT];
  Ship *_ship;
  Missile *_missiles[MAX_MISSILES];
  Missile *_missilesEnemy[MAX_EN_MISSILES];
  Enemy *_enemies[MAX_ENEMIES];
  Background *_backgrounds[MAX_BACKGROUNDS];
  Bonus *_bonuses[MAX_BONUS];
  unsigned int _turn;
  unsigned int _score;

  void _handleShip(int);
  void _handleBackground();
  void _handleMissiles();
  void _handleEnemies();
  void _handleBonus();
  void _enemyFireMissile(Enemy * enemy);
  void _shipFireMissile(bool * shooted, bool doubleShot);
  Enemy *_enemySpawner();
  void _spawn();

  Game(Game const &src);
  Game &operator=(Game const &src);

public:
  Game();
  virtual ~Game();

  char *update(int input);
  void addNewBackGroundElem(int, int, char);
  void setArena(int, char);
  int getScore(void) const;
  int getLives(void) const;
};

#endif // GAME_HPP