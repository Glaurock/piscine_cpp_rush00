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
    this->_end = newwin(ARENA_HEIGHT / 3, ARENA_WIDTH / 3, ARENA_HEIGHT / 3, ARENA_WIDTH / 3);
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
        return 4;
    case 'Y':
        return 4;
    case '|':
        return 3;
    case 'H':
        return 4;
    case 'o':
        return 2;
    case 'S':
        return 5;
    case '*':
        return 1;
    }
}

void Display::displayScore(Game const &game)
{
    int score = game.getScore();
    int lives = game.getLives();
    int row;
    int col;
    getmaxyx(this->_end, row, col);
    if (lives == 0)
    {
        wborder(this->_end, '|', '|', '-', '-', '+', '+', '+', '+');
        mvwprintw(this->_end, (row / 2), (col - 9) / 2, "GAME OVER");
        mvwprintw(this->_end, (row / 2 + 1), (col - 18) / 2, "PRESS ESC TO QUIT");
        wrefresh(this->_end);
        return;
    }
    mvwprintw(this->_score, 1, 2, "Score:              %d", score);
    wmove(this->_score, 3, 2);
    //   mvwprintw(this->_score, 2, 2, "Score:              %d", score);
    wattron(this->_score, COLOR_PAIR(5));
    for (int i = 0; i < 5; i++)
    {
        wmove(this->_score, 3, 2 + i * 2);
        if (i < lives)
            waddch(this->_score, 'S');
        else
        {
            wattroff(this->_score, COLOR_PAIR(5));
            waddch(this->_score, ' ');
        }
    }
    wattroff(this->_score, COLOR_PAIR(5));
    wrefresh(this->_score);
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