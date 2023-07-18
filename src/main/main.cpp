
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

    // The touchwin func raises a flag in the WINDOW structure to inform the refresh func that all lines have changed.
    touchwin(stdscr);
    refresh();

    usleep(40000);

  } while (key != ESC && x_pos > 0);

  endwin();
  return 0;
}
