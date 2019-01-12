#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <ncurses.h>
# include <iostream>
# include "ft_retro.hpp"

class Display {

private:

    Display(Display const & src);
    Display & operator=(Display const & src);

public:
    WINDOW * _win;

    Display();
    virtual ~Display();

    void draw(char *arena); 
    int getInput();   
};

# endif // DISPLAY_HPP