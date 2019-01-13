#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "AGameEntity.hpp"
#include "Game.hpp"

class Game;

class Background : public AGameEntity
{
private:
  Background(Background const &src);
  Background &operator=(Background const &src);
  Background();


public:
  Background(int, int, int, char);
  virtual ~Background();

  static int getNextFreeSpace(Background **backgrounds);
  static void popMountain(Game *game);
  static void bigMountain(Game *game);
  static void createRightMountain(Game *game, int size);
  static void createLeftMountain(Game *game, int size);

  int move(int, char *arena);

  static unsigned int mountainCounter;
  static bool mountainSide;
  static bool left;
};

#endif // Background_HPP