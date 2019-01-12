#include "Display.hpp"

Display::Display() {
    initscr();
    noecho();
    cbreak();
    start_color();
    this->_win = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
    keypad(this->_win, TRUE);
}

Display::Display(Display const & src) {}

Display::~Display() {
    endwin();
}

int Display::getInput() {
    return wgetch(this->_win);
}

void Display::draw(char *arena) {
    curs_set(0);
    wrefresh(this->_win);
    mvwprintw(this->_win, 0, 0, arena);
    wborder(this->_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(this->_win);
}


Display & Display::operator=(Display const & src) {}