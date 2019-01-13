#include "Display.hpp"
#include "Game.hpp"

#include <unistd.h> /*sleep*/
#include <time.h>

int main()
{
    Display display;
    Game *game = new Game;
    char *arena;
    int input;
    int speed = 30000;
    clock_t t;
    t = clock();
    int timer;
    while (1)
    {
        input = display.getInput();
        if (input == 27)
        {
            delete game;
            endwin();
            return (0);
        }
        arena = game->update(input);
        if (game->getLives() == 0)
        {
            delete game;
            display.game_over();
            while (1)
            {
                input = display.getInput();
                if (input == 27)
                {
                    endwin();
                    return (0);
                }
            }
        }
        display.draw(arena);
        timer = clock() - t;
        display.displayScore(*game, timer);
        usleep(speed);
        if (speed > 25000)
            speed -= 10;
    }

    return (0);
}