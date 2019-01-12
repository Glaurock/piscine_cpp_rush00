#include "Game.hpp"

Game::Game() {
  std::memset(this->_arena, ' ', ARENA_WIDTH * ARENA_HEIGHT);
  this->_ship = new Ship();

  for (int i = 0; i < MAX_BACKGROUNDS; i++)
    (this->_backgrounds[i] = NULL);

  for (int i = 0; i < MAX_ENEMIES; i++)
    (this->_enemies[i] = NULL);

  for (int i = 0; i < MAX_MISSILES; i++)
    (this->_missiles[i] = NULL);
  this->_enemies[0] = new Enemy();
}

Game::Game(Game const &src) {}

Game::~Game() {
  // TODO: DELETE THINGS
}

char *Game::update(int input) {

  /* Do some modification on the arena here */
  std::memset(this->_arena, ' ',
              ARENA_WIDTH *
                  ARENA_HEIGHT); // Clearing last frame info completely
  this->_ship->move(input);
  this->_arena[this->_ship->getCoordinate()] =
      this->_ship->getType(); // move player

  for (int i = 0; i < MAX_BACKGROUNDS; i++) // Move backgrounds first
    if (this->_backgrounds[i] != NULL) {
      this->_backgrounds[i]->move();
      this->_arena[this->_backgrounds[i]->getCoordinate()] =
          this->_backgrounds[i]->getType();
    }

  for (int i = 0; i < MAX_ENEMIES;
       i++) // move ennemies: if they hit the player they destroy it. If they
            // hit a background, push them and check again?
    if (this->_enemies[i] != NULL) {
      this->_enemies[i]->move();
      if (this->_enemies[i]->getCoordinate() >
          (ARENA_HEIGHT * ARENA_WIDTH) - 1) {
        delete this->_enemies[i];
        this->_enemies[i] = new Enemy();
      }
      if (this->_arena[this->_enemies[i]->getCoordinate()] == 'S')
        this->_ship
            ->collided(); // we have to implement a live system, respawn at
                          // neutral coordinates, flashes while invulnerable
      this->_arena[this->_enemies[i]->getCoordinate()] =
          this->_enemies[i]->getType();
    }

  for (int i = 0; i < MAX_MISSILES;
       i++) // move missiles last. if they hit an enemy,destroy it
    if (this->_missiles[i] != NULL) {
      this->_missiles[i]->move();
      // if (this->_arena[this->_enemies[i]->getCoordinate()] != ' ')
      this->_arena[this->_missiles[i]->getCoordinate()] =
          this->_missiles[i]->getType();
    }

  std::ofstream ofs;
  ofs.open(".log", std::ofstream::out | std::ofstream::app);
  ofs << input << std::endl;
  ofs.close();

  return this->_arena;
}

Game &Game::operator=(Game const &src) {}