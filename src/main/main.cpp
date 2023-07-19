
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef __linux__
#include <ncurses.h>
#else
#include "curses.h"
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

static inline void mv_str(int y, int x, const std::string& str)
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
  // Set sleep time
  std::chrono::microseconds duration(40000);

  refresh();

  do
  {
    // clear
    erase();
    x_pos--;

    mv_str(y - 10, x_pos, SL_LOGO_LINE_001);
    mv_str(y - 9, x_pos, SL_LOGO_LINE_002);
    mv_str(y - 8, x_pos, SL_LOGO_LINE_003);
    mv_str(y - 7, x_pos, SL_LOGO_LINE_004);
    mv_str(y - 6, x_pos, SL_LOGO_LINE_005);
    mv_str(y - 5, x_pos, SL_LOGO_LINE_006);
    mv_str(y - 4, x_pos, SL_LOGO_LINE_007);
    mv_str(y - 3, x_pos, SL_LOGO_LINE_008);
    mv_str(y - 2, x_pos, SL_LOGO_LINE_009);
    mv_str(y - 1, x_pos, SL_LOGO_LINE_010);
    mv_str(y + 0, x_pos, SL_LOGO_LINE_011);
    mv_str(y + 1, x_pos, SL_LOGO_LINE_012);
    mv_str(y + 2, x_pos, SL_LOGO_LINE_013);
    mv_str(y + 3, x_pos, SL_LOGO_LINE_014);
    mv_str(y + 4, x_pos, SL_LOGO_LINE_015);
    mv_str(y + 5, x_pos, SL_LOGO_LINE_016);
    mv_str(y + 6, x_pos, SL_LOGO_LINE_017);
    mv_str(y + 7, x_pos, SL_LOGO_LINE_018);
    mv_str(y + 8, x_pos, SL_LOGO_LINE_019);
    mv_str(y + 9, x_pos, SL_LOGO_LINE_020);
    mv_str(y + 10, x_pos, SL_LOGO_LINE_021);

#if 0
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
#endif
    refresh();

    std::this_thread::sleep_for(duration);
  }
  while (x_pos > (-SL_LOGO_MAX_LINE_SIZE));

  endwin();
  return 0;
}
