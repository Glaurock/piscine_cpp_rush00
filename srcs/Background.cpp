#include "Background.hpp"

Background::Background(int x, int y, int velocity, char type) : AGameEntity(x, y, velocity, type) {}

Background::~Background() {}

int Background::move(int turn, char *arena)
{
    if (turn % this->_velocity == 0)
        this->_y++;
    if (this->_y >= ARENA_HEIGHT)
    {
        this->_y = -1;
        this->_x = -1;
    }
    if (arena[0])
        return 0;
    return 0;
}

void Background::createRightMountain(Game *game, int size)
{
    for (int i = 1; i < size; i++)
        game->addNewBackGroundElem(ARENA_WIDTH - i - 1, 0, '*');
}

void Background::createLeftMountain(Game *game, int size)
{
    for (int i = 1; i < size; i++)
        game->addNewBackGroundElem(i, 0, '*');
}

void Background::popMountain(Game *game)
{
    int size = rand() % MAX_BACKGROUNDS_SIZE + 2;
    Background::createLeftMountain(game, size);
    size = rand() % MAX_BACKGROUNDS_SIZE + 2;
    Background::createRightMountain(game, size);
}

void Background::bigMountain(Game *game)
{
    if (Background::mountainCounter == 0) {
        Background::left = rand() % 2;
        Background::size = rand() % MOUNTAIN_MAX_SIZE;
    }

    Background::left ? 
        Background::createLeftMountain(game, Background::mountainCounter) : 
        Background::createRightMountain(game, Background::mountainCounter);

    if (Background::mountainCounter == Background::size)
        Background::mountainSide = true;
    if (!Background::mountainSide)
        Background::mountainCounter++;
    else
        Background::mountainCounter--;
    if (Background::mountainCounter == 0)
        Background::mountainSide = false;
}

int Background::getNextFreeSpace(Background **backgrounds)
{
    for (int i = 0; i < MAX_BACKGROUNDS; i++)
    {
        if (backgrounds[i] == NULL)
            return i;
    }
    return -1;
}

unsigned int Background::mountainCounter = 0;
bool Background::mountainSide = false;
bool Background::left = false;
unsigned int Background::size = 0;