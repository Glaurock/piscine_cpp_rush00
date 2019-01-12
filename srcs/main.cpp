#include "Display.hpp"
#include "Game.hpp"

#include <unistd.h> /*sleep*/

int main() {
    Display display;
    Game game;
    char *arena;
    int input;

    while(1) {
        input = display.getInput();
        arena = game.update(input);
        display.draw(arena);
        usleep(100000);
    }

    return (0);
}