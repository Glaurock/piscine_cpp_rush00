#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <ncurses.h>
# include <cstring>
# include <iostream>

# define ARENA_WIDTH 100
# define ARENA_HEIGHT 30

class Display {

private:
    WINDOW * _win;

    Display(Display const & src);
    Display & operator=(Display const & src);

public:
    Display();
    virtual ~Display();

    void draw(char *arena);    
};

# endif // DISPLAY_HPP