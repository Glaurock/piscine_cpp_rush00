#include "Display.hpp"

Display::Display()
{
    initscr();
    noecho();
    cbreak();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    init_pair(6, COLOR_BLUE, COLOR_BLUE);
    this->_win = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
    this->_score = newwin(10, 30, 0, ARENA_WIDTH + 5);
    keypad(this->_win, TRUE);
    nodelay(this->_win, true);
}

Display::Display(Display const &src) {}

Display::~Display() { endwin(); }

int Display::getInput() { return wgetch(this->_win); }

int getColor(char c)
{
    switch (c)
    {
    case ' ':
        return 0;
    case 'T':
        return 1;
    case '|':
        return 3;
    case 'H':
        return 1;
    case 'o':
        return 2;
    case 'S':
        return 5;
    case '*':
        return 1;
    }
}

void Display::draw(char *arena)
{
    int color;
    curs_set(0);
    wrefresh(this->_win);
    wmove(this->_win, 0, 0);
    for (int i = 0; i < (ARENA_HEIGHT * ARENA_WIDTH); i++)
    {
        color = getColor(arena[i]);
        if (color)
            wattron(this->_win, COLOR_PAIR(color));
        waddch(this->_win, arena[i]);
        if (color)
            wattroff(this->_win, COLOR_PAIR(color));
    }
    wborder(this->_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(this->_score, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(this->_win);
    wrefresh(this->_score);
}

Display &Display::operator=(Display const &src) {}