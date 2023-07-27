
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

static inline void usage(const char* progname)
{
  // Output command line parameter.
  std::cout << std::endl
            << progname
            << " <Mode>"
            << std::endl;
  std::cout << "i.e.," << std::endl;
  std::cout << progname << " 1" << std::endl << std::endl;

  std::cout << "------- MODE -------" << std::endl;
  std::cout << " 0  : Default straylight logo." << std::endl;
  std::cout << " 1  : Color straylight logo." << std::endl << std::endl;
  std::cout << " 99 : Display usage." << std::endl << std::endl;
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
    usage(argv[0]);
    return -1;
  }

  // Set option
  int mode = 0;
  if (argc == 2)
  {
    mode = std::atoi(argv[1]);
  }

  // Convert mode
  LogoMode logoMode = (LogoMode)mode;
  if (logoMode == LogoMode::HELP)
  {
    usage(argv[0]);
    return -1;
  }

  // Init
  init_curses();

  // Output logo
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
