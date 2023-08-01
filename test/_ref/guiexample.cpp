
/**
 * ref : http://linuxmag.osdn.jp/Japanese/March2002/article233.shtml
 */

#include <ncurses.h>
#include <stdlib.h>

#define ENTER 10
#define ESCAPE 27

/**
 *  init
 */
void init_curses()
{
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_RED, COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
}

/**
 * draw menubar
 */
void draw_menubar(WINDOW *menubar)
{
  wbkgd(menubar, COLOR_PAIR(2));
  waddstr(menubar, "MENU1");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F1)");
  wattroff(menubar, COLOR_PAIR(3));
  wmove(menubar, 0, 20);
  waddstr(menubar, "MENU2");
  wattron(menubar, COLOR_PAIR(3));
  waddstr(menubar, "(F2)");
  wattroff(menubar, COLOR_PAIR(3));
}

/**
 * draw menu
 */
WINDOW **draw_menu(int start_col)
{
  WINDOW **items = nullptr;
  items = (WINDOW **)malloc(9 * sizeof(WINDOW *));

  items[0] = newwin(10, 19, 1, start_col);
  wbkgd(items[0], COLOR_PAIR(2));
  box(items[0], ACS_VLINE, ACS_HLINE);
  items[1] = subwin(items[0], 1, 17, 2, start_col + 1);
  items[2] = subwin(items[0], 1, 17, 3, start_col + 1);
  items[3] = subwin(items[0], 1, 17, 4, start_col + 1);
  items[4] = subwin(items[0], 1, 17, 5, start_col + 1);
  items[5] = subwin(items[0], 1, 17, 6, start_col + 1);
  items[6] = subwin(items[0], 1, 17, 7, start_col + 1);
  items[7] = subwin(items[0], 1, 17, 8, start_col + 1);
  items[8] = subwin(items[0], 1, 17, 9, start_col + 1);
  for (int i = 0; i < 9; i++)
  {
    wprintw(items[i], "Item%d", i);
  }
  wbkgd(items[1], COLOR_PAIR(1));
  wrefresh(items[0]);
  return items;
}


