#include "Background.hpp"

Background::Background(int x, int y, int velocity, char type):
    AGameEntity(x, y, velocity, type) {}

Background::~Background() {}

void Background::move() { 
    this->_y += this->_velocity; 
    if (this->_y >= ARENA_HEIGHT) {
        this->_y = -1;
        this->_x = -1;
    }    
}

void Background::popMountain(Game * game) {
    int size = rand() % 6 + 1;

    for (int i = 1; i < size; i++) {
        game->addNewBackGroundElem(i, 0);
    }
    size = rand() % 6 + 1;
    for (int i = 1; i < size; i++) {
        game->addNewBackGroundElem(ARENA_WIDTH - i - 1, 0);
    }   
}

int Background::getNextFreeSpace(Background ** backgrounds) {
    for (int i = 0; i < MAX_BACKGROUNDS; i++) {
        if (backgrounds[i] == NULL) 
            return i;
    }
    return -1;
}