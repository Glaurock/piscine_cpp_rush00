#include "Game.hpp"

Game::Game() : _turn(0), _score(0) {
  std::memset(this->_arena, ' ', ARENA_WIDTH * ARENA_HEIGHT);
  this->_ship = new Ship();

  for (int i = 0; i < MAX_BACKGROUNDS; i++)
    (this->_backgrounds[i] = NULL);

  for (int i = 0; i < MAX_ENEMIES; i++)
    (this->_enemies[i] = NULL);

  for (int i = 0; i < MAX_MISSILES; i++)
    (this->_missiles[i] = NULL);
  this->_enemies[0] = new Hurler();
  this->_enemies[1] = new Slicer();
}

Game::Game(Game const &src) {}

Game::~Game() {
  // TODO: DELETE THINGS
}

Enemy * Game::_enemySpawner() {
  
  Enemy * enemy;

  switch (rand() % 4)
  {
    case 0:
      enemy = new Hurler();
      break;
    case 1:
      enemy = new Slicer();
      break;
    case 2:
      enemy = new Boss();
      break;
    default:
      enemy = new Enemy();
      break;
  }
  return enemy;
}

void Game::setArena(int pos, char type) {
  this->_arena[pos] = type;
}

void Game::_handleShip(int input) {

  if (input == 32) { // MACRO FOR SPACE?
    Missile *shot;
    shot = this->_ship->fireMissile();
    for (int i = 0; i < MAX_MISSILES; i++) {
      if (this->_missiles[i] == NULL) {
        this->_missiles[i] = shot;
        return;
      }
    }
    /* If we are here, we cannot fire more missiles */
    delete shot;
  }
  this->_ship->move(input);
  if (this->_arena[this->_ship->getCoordinate()] != ' ')
    this->_ship->collided();
  this->_arena[this->_ship->getCoordinate()] = this->_ship->getType();
}

void Game::addNewBackGroundElem(int x, int y) {
  Background *elem = new Background(x, y, 1, '*');
  int i = Background::getNextFreeSpace(this->_backgrounds);
  this->_backgrounds[i] = elem;
}

void Game::_handleBackground() {
  /* background spawner : un a droite un a gauche */
  /* every 10 turn, spawn a bar */
  Background::popMountain(this);

  for (int i = 0; i < MAX_BACKGROUNDS; i++) // Move backgrounds first
    if (this->_backgrounds[i] != NULL) {
      this->_backgrounds[i]->move(this->_turn);
      if (this->_backgrounds[i]->getXCoordinate() == -1 &&
          this->_backgrounds[i]->getYCoordinate() == -1) {
        delete this->_backgrounds[i];
        this->_backgrounds[i] = NULL;
        continue;
      }
      this->_arena[this->_backgrounds[i]->getCoordinate()] =
          this->_backgrounds[i]->getType();
    }
}

void Game::_handleMissiles() {

  for (int i = 0; i < MAX_MISSILES;
       i++) // move missiles last. if they hit an enemy,destroy it
    if (this->_missiles[i] != NULL) {
      this->_missiles[i]->move(this->_turn);
      if (this->_missiles[i]->getXCoordinate() == -1 &&
          this->_missiles[i]->getYCoordinate() == -1) {
        delete this->_missiles[i];
        this->_missiles[i] = NULL;
        continue;
      }
      this->_arena[this->_missiles[i]->getCoordinate()] =
          this->_missiles[i]->getType();
    }
}

void Game::_handleEnemies() {
  for (int i = 0; i < MAX_ENEMIES;
       i++) // move ennemies: if they hit the player they destroy it. If they
            // hit a background, push them and check again?
    if (this->_enemies[i] != NULL) {
      this->_enemies[i]->move(this->_turn);
      if (this->_enemies[i]->getCoordinate() >
          (ARENA_HEIGHT * ARENA_WIDTH) - 1) {
        delete this->_enemies[i];
        this->_enemies[i] = this->_enemySpawner();
      }
      if (this->_arena[this->_enemies[i]->getCoordinate()] ==
          this->_ship->getType())
        this->_ship->collided();
      else if (this->_arena[this->_enemies[i]->getCoordinate()] ==
               Missile::_type) {
        for (int x = 0; x < MAX_MISSILES; x++)
          if (this->_missiles[x] != NULL)
            if (this->_missiles[x]->getCoordinate() ==
                this->_enemies[i]->getCoordinate()) {
              delete this->_missiles[x];
              this->_missiles[x] = NULL;
              // break;
            }
        if (this->_enemies[i]->collided()) {
          this->_arena[this->_enemies[i]->getCoordinate()] = 'X';
          delete this->_enemies[i];
          this->_enemies[i] = NULL;
          // this->_enemies[i] = new Enemy(); // get score
        }
      } else {
        // NEW WAY OF HANDLE DRAW, IS THIS OK WE THE REST OF THE CODE?
        // if this is a boss, call draw() function
        if (this->_enemies[i]->getType() == 'o') {
          this->_enemies[i]->draw(this);
        } else {
          this->_arena[this->_enemies[i]->getCoordinate()] =
              this->_enemies[i]->getType();
        }
      }
    }
}

char *Game::update(int input) {

  this->_turn++;

  /* Do some modification on the arena here */
  std::memset(this->_arena, ' ',
              ARENA_WIDTH *
                  ARENA_HEIGHT); // Clearing last frame info completely

  this->_handleBackground();
  this->_handleShip(input);
  this->_handleMissiles();
  this->_handleEnemies();
  
  return this->_arena;
}

Game &Game::operator=(Game const &src) {}