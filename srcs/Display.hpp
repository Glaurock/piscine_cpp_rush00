#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <ncurses.h>
# include <iostream>
# include "ft_retro.hpp"

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