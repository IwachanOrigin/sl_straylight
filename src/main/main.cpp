
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
  keypad(stdscr, true);
}

int main(int argc, char *argv[])
{
  int key;

  // init
  init_curses();

  // Set max width
  int x_pos = COLS;

  refresh();

  do
  {
    // clear
    erase();
    x_pos--;
    
    mvwprintw(stdscr, 2, x_pos, "%s", SL_LOGO_LINE_001.c_str());
    mvwprintw(stdscr, 3, x_pos, "%s", SL_LOGO_LINE_002.c_str());
    mvwprintw(stdscr, 4, x_pos, "%s", SL_LOGO_LINE_003.c_str());
    mvwprintw(stdscr, 5, x_pos, "%s", SL_LOGO_LINE_004.c_str());
    mvwprintw(stdscr, 6, x_pos, "%s", SL_LOGO_LINE_005.c_str());
    mvwprintw(stdscr, 7, x_pos, "%s", SL_LOGO_LINE_006.c_str());
    mvwprintw(stdscr, 8, x_pos, "%s", SL_LOGO_LINE_007.c_str());
    mvwprintw(stdscr, 9, x_pos, "%s", SL_LOGO_LINE_008.c_str());
    mvwprintw(stdscr, 10, x_pos, "%s", SL_LOGO_LINE_009.c_str());
    mvwprintw(stdscr, 11, x_pos, "%s", SL_LOGO_LINE_010.c_str());
    mvwprintw(stdscr, 12, x_pos, "%s", SL_LOGO_LINE_011.c_str());
    mvwprintw(stdscr, 13, x_pos, "%s", SL_LOGO_LINE_012.c_str());
    mvwprintw(stdscr, 14, x_pos, "%s", SL_LOGO_LINE_013.c_str());
    mvwprintw(stdscr, 15, x_pos, "%s", SL_LOGO_LINE_014.c_str());
    mvwprintw(stdscr, 16, x_pos, "%s", SL_LOGO_LINE_015.c_str());
    mvwprintw(stdscr, 17, x_pos, "%s", SL_LOGO_LINE_016.c_str());
    mvwprintw(stdscr, 18, x_pos, "%s", SL_LOGO_LINE_017.c_str());
    mvwprintw(stdscr, 19, x_pos, "%s", SL_LOGO_LINE_018.c_str());
    mvwprintw(stdscr, 20, x_pos, "%s", SL_LOGO_LINE_019.c_str());
    mvwprintw(stdscr, 21, x_pos, "%s", SL_LOGO_LINE_020.c_str());
    mvwprintw(stdscr, 22, x_pos, "%s", SL_LOGO_LINE_021.c_str());

    // The touchwin func raises a flag in the WINDOW structure to inform the refresh func that all lines have changed.
    touchwin(stdscr);
    refresh();

    usleep(50000);

  }
  while (key != ESC && x_pos > 0);

  endwin();
  return 0;
}
