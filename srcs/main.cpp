#include "Display.hpp"
#include "Game.hpp"

#include <unistd.h> /*sleep*/

int main()
{
    Display display;
    Game *game = new Game;
    char *arena;
    int input;
    int speed = 30000;
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
        display.displayScore(*game);
        usleep(speed);
        if (speed > 25000)
            speed -= 10;
    }

    return (0);
}