
#include "outputlogo.h"

#ifdef __linux__
#include <ncurses.h>
#else
#include "curses.h"
#endif

void OutputLogo::displayStr(int y, int x, const std::string& str)
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
