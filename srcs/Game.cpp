#include "Game.hpp"

Game::Game() {
    std::memset(this->_arena, ' ', ARENA_WIDTH * ARENA_HEIGHT);
    this->_ship = new Ship();
}

Game::Game(Game const & src) {}

Game::~Game() {
    // TODO: DELETE THINGS
}

char * Game::update() {
    /* Do some modification on the arena here */

    this->_arena[this->_ship->getCoordinate()] = this->_ship->getType();
    // std::ofstream ofs;
    // ofs.open(".log", std::ofstream::out | std::ofstream::app);
    // ofs << this->_ship->getCoordinate() << std::endl;
    // ofs.close();

    return this->_arena;
}


Game & Game::operator=(Game const & src) {}