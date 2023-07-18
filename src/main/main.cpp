
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef __linux__
#include <ncurses.h>
#include <unistd.h>
#endif

#include "straylight.h"

#define ENTER 10
#define ESC 27

#define CAT1 " /\\_/\\ "
#define CAT2 "( o.o ) "
#define CAT3 " > ^ < "

static inline void init_curses()
{
  initscr();
  curs_set(0);
  noecho();
  nodelay(stdscr, true);
  leaveok(stdscr, true);
  scrollok(stdscr, false);
}

static inline void mv_str(int& y, int& x, const std::string& str)
{
  int strPos = 0;
  for (; x < 0; ++x, strPos++)
  {
    if (strPos >= str.length())
    {
      return;
    }
  }
  for (; strPos < str.length(); x++, strPos++)
  {
    mvaddch(y, x, str[strPos]);
  }
}

int main(int argc, char *argv[])
{
  // init
  init_curses();

  // Set max width
  int x_pos = COLS - 1;
  int y = LINES / 2;
  refresh();

  do
  {
    // clear
    erase();
    x_pos--;

    mvwprintw(stdscr, y - 10, x_pos, "%s", SL_LOGO_LINE_001.c_str());
    mvwprintw(stdscr, y - 9, x_pos, "%s", SL_LOGO_LINE_002.c_str());
    mvwprintw(stdscr, y - 8, x_pos, "%s", SL_LOGO_LINE_003.c_str());
    mvwprintw(stdscr, y - 7, x_pos, "%s", SL_LOGO_LINE_004.c_str());
    mvwprintw(stdscr, y - 6, x_pos, "%s", SL_LOGO_LINE_005.c_str());
    mvwprintw(stdscr, y - 5, x_pos, "%s", SL_LOGO_LINE_006.c_str());
    mvwprintw(stdscr, y - 4, x_pos, "%s", SL_LOGO_LINE_007.c_str());
    mvwprintw(stdscr, y - 3, x_pos, "%s", SL_LOGO_LINE_008.c_str());
    mvwprintw(stdscr, y - 2, x_pos, "%s", SL_LOGO_LINE_009.c_str());
    mvwprintw(stdscr, y - 1, x_pos, "%s", SL_LOGO_LINE_010.c_str());
    mvwprintw(stdscr, y + 0, x_pos, "%s", SL_LOGO_LINE_011.c_str());
    mvwprintw(stdscr, y + 1, x_pos, "%s", SL_LOGO_LINE_012.c_str());
    mvwprintw(stdscr, y + 2, x_pos, "%s", SL_LOGO_LINE_013.c_str());
    mvwprintw(stdscr, y + 3, x_pos, "%s", SL_LOGO_LINE_014.c_str());
    mvwprintw(stdscr, y + 4, x_pos, "%s", SL_LOGO_LINE_015.c_str());
    mvwprintw(stdscr, y + 5, x_pos, "%s", SL_LOGO_LINE_016.c_str());
    mvwprintw(stdscr, y + 6, x_pos, "%s", SL_LOGO_LINE_017.c_str());
    mvwprintw(stdscr, y + 7, x_pos, "%s", SL_LOGO_LINE_018.c_str());
    mvwprintw(stdscr, y + 8, x_pos, "%s", SL_LOGO_LINE_019.c_str());
    mvwprintw(stdscr, y + 9, x_pos, "%s", SL_LOGO_LINE_020.c_str());
    mvwprintw(stdscr, y + 10, x_pos, "%s", SL_LOGO_LINE_021.c_str());

    refresh();

    usleep(40000);
  }
  while (x_pos > 0);

  endwin();
  return 0;
}
