#include "Background.hpp"

Background::Background(int x, int y, int velocity, char type):
    AGameEntity(x, y, velocity, type) {}

Background::~Background() {}

void Background::move() { 
    this->_y += this->_velocity; 
    if (this->_y >= ARENA_HEIGHT - 1) {
        this->_y = -1;
        this->_x = -1;
    }    
}

int Background::getNextFreeSpace(Background ** backgrounds) {
    for (int i = 0; i < MAX_BACKGROUNDS; i++) {
        if (backgrounds[i] == NULL) 
            return i;
    }
    return -1;
}