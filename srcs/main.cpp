#include "Display.hpp"
#include "Game.hpp"

int main() {
    Display display;
    Game game;
    char *arena;

    while(1) {
        arena = game.update();
        display.draw(arena);
    }

    return (0);
}