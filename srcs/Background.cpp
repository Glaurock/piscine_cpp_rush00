#include "Background.hpp"

Background::Background(int x, int y, int velocity, char type) : AGameEntity(x, y, velocity, type) {}

Background::~Background() {}

void Background::move(int turn, char *arena)
{
    this->_y++;
    if (this->_y >= ARENA_HEIGHT)
    {
        this->_y = -1;
        this->_x = -1;
    }
}

void Background::popMountain(Game *game)
{
    int size = rand() % MAX_BACKGROUNDS_SIZE + 2;

    for (int i = 1; i < size; i++)
    {
        game->addNewBackGroundElem(i, 0);
    }
    size = rand() % MAX_BACKGROUNDS_SIZE + 2;
    for (int i = 1; i < size; i++)
    {
        game->addNewBackGroundElem(ARENA_WIDTH - i - 1, 0);
    }
}

void Background::bigMountain(Game *game)
{
    for (int i = 1; i < Background::mountainCounter; i++)
    {
        game->addNewBackGroundElem(i, 0);
    }
    if (Background::mountainCounter == MOUNTAIN_MAX_SIZE)
        Background::mountainSide = true;
    if (!Background::mountainSide)
    {
        Background::mountainCounter++;
    }
    else
    {
        Background::mountainCounter--;
    }
    if (Background::mountainCounter == 0)
    {
        Background::mountainSide = false;
    }
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