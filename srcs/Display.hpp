#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "ft_retro.hpp"
#include <iostream>
#include <ncurses.h>
#include "Game.hpp"

class Display
{

private:
  Display(Display const &src);
  Display &operator=(Display const &src);

public:
  WINDOW *_win;
  WINDOW *_score;
  WINDOW *_end;
  Display();
  virtual ~Display();

  void game_over(void);
  void draw(char *arena);
  void displayScore(Game const &game, int timer);
  int getInput();
};

#endif // DISPLAY_HPP