#include "Display.hpp"

Display::Display() {
    initscr();
    noecho();
    cbreak();
    start_color();
    this->_win = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
}

Display::Display(Display const & src) {}

Display::~Display() {
    // TODO: DESTROY THINGS FOR NCURSES?
}

void Display::draw(char *arena) {
    curs_set(0);
    wrefresh(this->_win);
    mvwprintw(this->_win, 0, 0, arena);
    wborder(this->_win, '|', '|', '-', '-', '+', '+', '+', '+');
}


Display & Display::operator=(Display const & src) {}