#include "Display.hpp"
#include "Game.hpp"

#include <unistd.h> /*sleep*/

int main() {
  Display display;
  Game game;
  char *arena;
  int input;
  int speed = 50000;
  while (1) {
    input = display.getInput();
    if (input == 27) {
      // before exiting, delete all mapped memory!
      std::exit(0);
    }
    arena = game.update(input);
    display.draw(arena);
    usleep(speed);
    if (speed > 35000)
      speed -= 10;
  }

  return (0);
}