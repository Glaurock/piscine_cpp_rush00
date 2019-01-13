#include "Boss.hpp"

Boss::Boss() {
    this->_velocity = 2;
    this->_type = 'o';
    this->_direction = 1;
    this->_size = sizeof(Boss::boss1) / sizeof(int);
    this->_surface = new Enemy*[this->_size]; /* Leaks here I think */
    for (int i = 0; i < this->_size; i++) {
        this->_surface[i] = new Enemy(Boss::boss1[i] % ARENA_WIDTH, Boss::boss1[i] / ARENA_WIDTH, 2, 1);
    }
}

Boss::~Boss() {
    // destruct game objects
}

void Boss::draw(Game * game) {
    for (int i = 0; i < this->_size; i++) {
        game->setArena(this->_surface[i]->getCoordinate(), this->_type);
    }
}

void Boss::move(int turn) {

    for (int i = 0; i < this->_size; i++) {
        this->_surface[i]->move(turn); // care when we will remove Enemy move function
    }
}

int Boss::getSize() const { return this->_size; }

int Boss::boss1[] = {141, 142, 241, 242, 340, 343};
