
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
#include "outputcolorlogo.h"

static inline void usage()
{
  
}

static inline void checkOpt(int& mode)
{
  switch(mode)
  {
    
  }
}

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
  if (argc > 2)
  {
    usage();
    return -1;
  }

  int mode = 0;
  checkOpt(mode);

  // init
  init_curses();
#if 0
  // Create
  OutputDefaultLogo odl;
  // Output BASE logo.
  odl.render();
#else
  // Create
  OutputColorLogo ocl;
  ocl.render();
#endif

  endwin();
  return 0;
}
