#include "Display.hpp"
#include "Game.hpp"

int main() {
    Display display;
    Game game;
    char *arena;
    int dir;

    while(1) {
        dir = display.getInput();
        arena = game.update(dir);
        display.draw(arena);
    }

    return (0);
}