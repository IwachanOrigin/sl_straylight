
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
#include "version.h"

static inline void usage(const char* progname)
{
  // Output command line parameter.
  std::cout << std::endl
            << progname
            << " <Mode>"
            << " <Flush>"
            << std::endl;
  std::cout << "i.e.," << std::endl;
  std::cout << progname << " 1 1" << std::endl << std::endl;

  std::cout << "------- MODE -------" << std::endl;
  std::cout << " 0  : Default straylight logo." << std::endl;
  std::cout << " 1  : Color straylight logo." << std::endl;
  std::cout << " 99 : Display usage." << std::endl << std::endl;

  std::cout << "------- FLUSH -------" << std::endl;
  std::cout << " 0  : flush off. default." << std::endl;
  std::cout << " 1  : flush on. Maybe break the console color." << std::endl << std::endl;

  std::cout << progname
            << " v" << SOFTWARE_VERSION_MAJOR
            << "." << SOFTWARE_VERSION_MINOR
            << "." << SOFTWARE_VERSION_PATCH
            << " " << SOFTWARE_GIT_SHA1_VAL
            << std::endl << std::endl;
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
  if (argc > 3)
  {
    usage(argv[0]);
    return -1;
  }

  // Set option
  int mode = 0;
  if (argc > 1)
  {
    mode = std::atoi(argv[1]);
  }
  int flush = 0;
  if (argc == 3)
  {
    flush = std::atoi(argv[2]);
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
  if (flush)
  {
    outputLogo->setFlushON();
  }
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
