
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

#include "outputdefaultlogo.h"

static inline void init_curses()
{
  initscr();
  curs_set(0);
  noecho();
  nodelay(stdscr, true);
  leaveok(stdscr, true);
  scrollok(stdscr, false);
}

int main(int argc, char *argv[])
{
  // init
  init_curses();

  // Create
  OutputDefaultLogo odl;
  // Output BASE logo.
  odl.render();

  endwin();
  return 0;
}
