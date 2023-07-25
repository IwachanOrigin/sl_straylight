
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

#include "outputlogofactory.h"
#include "outputlogo.h"

static inline void usage()
{
  
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

  // init
  init_curses();

  // set option
  int mode = 0;
  if (argc == 2)
  {
    mode = std::atoi(argv[1]);
  }

  // convert mode
  LogoMode logoMode = (LogoMode)mode;
  OutputLogoFactory olf;
  auto outputLogo =  olf.create(logoMode);
  outputLogo->render();

  endwin();

  // Release
  if (outputLogo)
  {
    delete outputLogo;
    outputLogo = nullptr;
  }

  return 0;
}
