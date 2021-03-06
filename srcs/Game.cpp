#include "Game.hpp"

Game::Game() : _turn(0), _score(0), _extra_score(50000)
{
  std::memset(this->_arena, ' ', ARENA_WIDTH * ARENA_HEIGHT);
  this->_ship = new Ship();

  for (int i = 0; i < MAX_BACKGROUNDS; i++)
    (this->_backgrounds[i] = NULL);

  for (int i = 0; i < MAX_ENEMIES; i++)
    (this->_enemies[i] = NULL);

  for (int i = 0; i < MAX_MISSILES; i++)
    (this->_missiles[i] = NULL);

  for (int i = 0; i < MAX_EN_MISSILES; i++)
    (this->_missilesEnemy[i] = NULL);

  for (int i = 0; i < MAX_BONUS; i++)
    (this->_bonuses[i] = NULL);

  this->_enemies[0] = this->_enemySpawner();
}

Game::~Game()
{
  for (int i = 0; i < MAX_BACKGROUNDS; i++)
  {
    if (this->_backgrounds[i] != NULL)
      delete this->_backgrounds[i];
    (this->_backgrounds[i] = NULL);
  }
  for (int i = 0; i < MAX_ENEMIES; i++)
  {
    if (this->_enemies[i] != NULL)
      delete this->_enemies[i];
    (this->_enemies[i] = NULL);
  }
  for (int i = 0; i < MAX_MISSILES; i++)
  {
    if (this->_missiles[i] != NULL)
      delete this->_missiles[i];
    (this->_missiles[i] = NULL);
  }
  for (int i = 0; i < MAX_EN_MISSILES; i++)
  {
    if (this->_missilesEnemy[i] != NULL)
      delete this->_missilesEnemy[i];
    (this->_missilesEnemy[i] = NULL);
  }
  delete this->_ship;
  // TODO: DELETE THINGS
}

void Game::_spawn()
{
  if (this->_turn % SPAWN_TURN == 0)
  {
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
      if (this->_enemies[i] == NULL)
      {
        this->_enemies[i] = this->_enemySpawner();
        break;
      }
    }
  }
  if (this->_turn % BOSS_SPAWN == 0)
  {
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
      if (this->_enemies[i] == NULL)
      {
        this->_enemies[i] = new Boss();
        break;
      }
    }
  }
}

Enemy *Game::_enemySpawner()
{
  Enemy *enemy;
  int x = rand() % (ARENA_WIDTH - 20) + 20;
  int y = rand() % 5 + 2;

  switch (rand() % 3)
  {
  case 0:
    enemy = new Hurler(x, y);
    break;
  case 1:
    enemy = new Slicer(x, y);
    break;
  default:
    enemy = new Enemy(x, y);
    break;
  }
  return enemy;
}

void Game::setArena(int pos, char type) { this->_arena[pos % ARENA_SIZE] = type; }

void Game::_shipFireMissile(bool *shooted, bool doubleShot)
{
  Missile *shot;
  shot = this->_ship->fireMissile(doubleShot);
  for (int i = 0; i < MAX_MISSILES; i++)
  {
    if (this->_missiles[i] == NULL)
    {
      this->_missiles[i] = shot;
      *shooted = true;
      break;
    }
  }
  /* If we are here, we cannot fire more missiles */
  if (!(*shooted))
    delete shot;
}

void Game::_handleShip(int input)
{
  bool shooted = false;
  /* Check enemy missiles collision */
  for (int i = 0; i < MAX_EN_MISSILES; i++)
  {
    if (this->_missilesEnemy[i] != NULL)
    {
      if (this->_missilesEnemy[i]->getCoordinate() == this->_ship->getCoordinate())
      {
        this->_ship->collided();
        delete this->_missilesEnemy[i];
        this->_missilesEnemy[i] = NULL;
        return;
      }
    }
  }

  if (input == 32)
  {
    this->_shipFireMissile(&shooted, false);
    if (this->_ship->getWeapon())
      this->_shipFireMissile(&shooted, true);
  }
  if (!shooted)
    this->_ship->move(input, this->_arena);
  if (this->_ship->getCollision(this->_arena) == 'B') {
    for (int i = 0; i < MAX_BONUS; i++) {
      if (this->_bonuses[i] != NULL) {
        if (this->_bonuses[i]->getCoordinate() == this->_ship->getCoordinate()) {
          delete this->_bonuses[i];
          this->_bonuses[i] = NULL;
          this->_ship->gainBonus();
        }
      }
    }
  } else if (this->_ship->getCollision(this->_arena) != 0)
    this->_ship->collided();
  this->_ship->draw(this->_arena);
}

void Game::addNewBackGroundElem(int x, int y, char type)
{
  if (this->_arena[(y * ARENA_WIDTH + x) % ARENA_SIZE] != ' ')
    return;
  Background *elem = new Background(x, y, 1, type);
  int i = Background::getNextFreeSpace(this->_backgrounds);
  this->_backgrounds[i] = elem;
}

void Game::_handleBackground()
{
  this->addNewBackGroundElem(rand() % (ARENA_SIZE + 10) - 10, 2, '.');

  Background::popMountain(this);
  if (Background::mountainCounter != 0 || this->_turn % 30 == 0)
  {
    Background::bigMountain(this);
  }

  for (int i = 0; i < MAX_BACKGROUNDS; i++) // Move backgrounds first
    if (this->_backgrounds[i] != NULL)
    {
      this->_backgrounds[i]->move(this->_turn, this->_arena);
      if (this->_backgrounds[i]->getXCoordinate() == -1 ||
          this->_backgrounds[i]->getYCoordinate() == -1)
      {
        delete this->_backgrounds[i];
        this->_backgrounds[i] = NULL;
        continue;
      }
      this->_backgrounds[i]->draw(this->_arena);
    }
}

void Game::_handleMissiles()
{
  for (int i = 0; i < MAX_MISSILES;
       i++) // move missiles last. if they hit an enemy,destroy it
    if (this->_missiles[i] != NULL)
    {
      this->_missiles[i]->move(this->_turn, this->_arena);
      if (this->_missiles[i]->getXCoordinate() == -1 ||
          this->_missiles[i]->getYCoordinate() == -1)
      {
        delete this->_missiles[i];
        this->_missiles[i] = NULL;
        continue;
      }
      this->_missiles[i]->draw(this->_arena);
    }

  /* Enemies missiles */
  for (int i = 0; i < MAX_EN_MISSILES; i++)
    if (this->_missilesEnemy[i] != NULL)
    {
      this->_missilesEnemy[i]->move(this->_turn, this->_arena);
      if (this->_missilesEnemy[i]->getXCoordinate() == -1 ||
          this->_missilesEnemy[i]->getYCoordinate() == -1)
      {
        delete this->_missilesEnemy[i];
        this->_missilesEnemy[i] = NULL;
        continue;
      }
      this->_missilesEnemy[i]->draw(this->_arena);
    }
}

void Game::_enemyFireMissile(Enemy *enemy)
{
  Missile *shot;
  shot = enemy->fireMissile();
  for (int i = 0; i < MAX_EN_MISSILES; i++)
  {
    if (this->_missilesEnemy[i] == NULL)
    {
      this->_missilesEnemy[i] = shot;
      return;
    }
  }
  delete shot;
}

void Game::_handleEnemies()
{
  char c;
  int destroyed = 0;

  for (int i = 0; i < MAX_ENEMIES; i++)
    if (this->_enemies[i] != NULL)
    {
      this->_enemies[i]->checkBorder(this->_arena);

      this->_enemies[i]->move(this->_turn, this->_arena);
      if (this->_enemies[i]->getType() == 'T' && this->_turn % 10 == 0)
        this->_enemyFireMissile(this->_enemies[i]);
      if (this->_enemies[i]->checkOutOfBounds())
      {
        while (!destroyed)
          destroyed = this->_enemies[i]->collided();
        delete this->_enemies[i];
        this->_enemies[i] = this->_enemySpawner();
      }
      if ((c = this->_enemies[i]->getCollision(this->_arena)))
      {
        switch (c)
        {
        case 'S':
        {
          this->_ship->collided();
          break;
        }
        case '|':
        {
          for (int x = 0; x < MAX_MISSILES; x++)
            if (this->_missiles[x] != NULL)
              if (this->_missiles[x]->getCoordinate() == this->_enemies[i]->getCoordinate())
              {
                delete this->_missiles[x];
                this->_missiles[x] = NULL;
                // break;
              }
          if (this->_enemies[i]->collided())
          {
            this->_arena[this->_enemies[i]->getCoordinate() % ARENA_SIZE] = 'X';
            if (this->_enemies[i]->getType() == 'o')
            {
              for (int j = 0; j < MAX_BONUS; j++)
              {
                if (this->_bonuses[j] == NULL)
                {
                  this->_bonuses[j] =
                      new Bonus(this->_enemies[i]->getXCoordinate(), this->_enemies[i]->getYCoordinate());
                }
              }
            }
            this->_score += this->_enemies[i]->getValue();
            delete this->_enemies[i];
            this->_enemies[i] = NULL;
          }
          break;
        }
        default:
          break;
        }
      }
      else
      {
        this->_enemies[i]->draw(this->_arena);
      }
    }
}

void Game::_handleBonus()
{
  for (int i = 0; i < MAX_BONUS; i++)
  {
    if (this->_bonuses[i] != NULL)
    {
      this->_bonuses[i]->move(this->_turn, this->_arena);
      if (this->_bonuses[i]->getYCoordinate() == -1)
      {
        delete this->_bonuses[i];
        this->_bonuses[i] = NULL;
        return ;
      }
     
      this->_bonuses[i]->draw(this->_arena);
    }
  }
}

int Game::getScore(void) const { return this->_score; }

int Game::getLives(void) const { return this->_ship->getLives(); }

char *Game::update(int input)
{
  this->_turn++;
  this->_score += 1;
  if (this->_score > _extra_score)
  {
    this->_ship->extraLife();
    this->_extra_score *= 2;
  }
  /* Do some modification on the arena here */
  std::memset(this->_arena, ' ',
              ARENA_WIDTH *
                  ARENA_HEIGHT); // Clearing last frame info completely

  this->_spawn();
  this->_handleBackground();
  this->_handleBonus();
  this->_handleShip(input);
  this->_handleMissiles();
  this->_handleEnemies();
  return this->_arena;
}
