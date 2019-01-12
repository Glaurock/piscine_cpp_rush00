/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <csimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:25:04 by csimon            #+#    #+#             */
/*   Updated: 2019/01/12 11:29:57 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <ncurses.h>

void cast_curses(void)
{
    char arena[50 * 200 - 1] = {'B'};
    std::memset(arena, ' ', (50 * 200 - 1));
    arena[1001] = 'A';
    arena[1002] = 'A';
    arena[1004] = 'A';
    std::cout << arena << std::endl;
    // char arena2[50 * 200 - 1] = {"" '};
    // WINDOW *newWin2;
    WINDOW *newWin;
    initscr();
    noecho();
    cbreak();
    start_color();
    newWin = newwin(50, 200, 0, 0);
    //   newWin2 = newwin(25, 100, 13, 75);
    init_color(COLOR_MAGENTA, 400, 400, 400);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    bkgd(COLOR_PAIR(1));
    wbkgd(newWin, COLOR_PAIR(3));
    //   wbkgd(newWin2, COLOR_PAIR(2));
    wborder(newWin, '|', '|', '-', '-', '+', '+', '+', '+');
    //   wborder(newWin2, '|', '|', '-', '-', '+', '+', '+', '+');
    refresh();
    wrefresh(newWin);
    curs_set(0);
    while (1)
    {
        curs_set(0);

        wrefresh(newWin);
        // redrawwin(newWin);
        // wrefresh(newWin2);
        mvwprintw(newWin, 0, 0, arena);
        wborder(newWin, '|', '|', '-', '-', '+', '+', '+', '+');
        // wprintw(newWin2, arena);
    }
    //   // return newWin;
}

int main(void)
{
    //     char arena[50 * 200] = {'A', ' '};
    //     //   arena =

    //     arena[60] = ' ';
    cast_curses();
    // while (1)
    // {
    //     wrefresh(win);
    //     wprintw(win, arena);
    // }
    return 0;
}
