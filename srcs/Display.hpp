#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <ncurses.h>

class Display {

private:
    Display();

    Display(Display const & src);
    Display & operator=(Display const & src);

public:
    virtual ~Display();

};

# endif // DISPLAY_HPP