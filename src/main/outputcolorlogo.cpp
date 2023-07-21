
#ifdef __linux__
#include <ncurses.h>
#else
#include "curses.h"
#endif

#include <chrono>
#include <thread>
#include "straylight.h"
#include "outputcolorlogo.h"

using namespace color_logo;

int OutputColorLogo::render()
{
  // Set max width
  int x_pos = COLS - 1;
  int y = LINES / 2;
  // Set color change parameters
  int i_start_pos_002 = SL_COLOR_LOGO_002_I_POS;
  int b_start_pos_002 = i_start_pos_002 + SL_COLOR_LOGO_PARTS_RED.size();
  int i_start_pos_003 = SL_COLOR_LOGO_003_I_POS;
  int b_start_pos_003 = i_start_pos_003 + SL_COLOR_LOGO_PARTS_RED.size();
  // Set sleep time
  std::chrono::microseconds duration(40000);
  // init color
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_RED);

  refresh();

  do
  {
    // clear
    erase();
    x_pos--;

    this->displayStr(y - 10, x_pos, SL_COLOR_LOGO_LINE_001);

    this->displayStr(y - 9, x_pos, SL_COLOR_LOGO_LINE_002_A);
    attron(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + i_start_pos_002, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + b_start_pos_002, SL_COLOR_LOGO_LINE_002_B);

    this->displayStr(y - 8, x_pos, SL_COLOR_LOGO_LINE_003_A);
    attron(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + i_start_pos_003, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + b_start_pos_003, SL_COLOR_LOGO_LINE_003_B);

    this->displayStr(y - 7, x_pos, SL_COLOR_LOGO_LINE_004);
    this->displayStr(y - 6, x_pos, SL_COLOR_LOGO_LINE_005);
    this->displayStr(y - 5, x_pos, SL_COLOR_LOGO_LINE_006);
    this->displayStr(y - 4, x_pos, SL_COLOR_LOGO_LINE_007);
    this->displayStr(y - 3, x_pos, SL_COLOR_LOGO_LINE_008);
    this->displayStr(y - 2, x_pos, SL_COLOR_LOGO_LINE_009);
    this->displayStr(y - 1, x_pos, SL_COLOR_LOGO_LINE_010);
    this->displayStr(y + 0, x_pos, SL_COLOR_LOGO_LINE_011);
    this->displayStr(y + 1, x_pos, SL_COLOR_LOGO_LINE_012);
    this->displayStr(y + 2, x_pos, SL_COLOR_LOGO_LINE_013);
    this->displayStr(y + 3, x_pos, SL_COLOR_LOGO_LINE_014);
    this->displayStr(y + 4, x_pos, SL_COLOR_LOGO_LINE_015);
    this->displayStr(y + 5, x_pos, SL_COLOR_LOGO_LINE_016);
    this->displayStr(y + 6, x_pos, SL_COLOR_LOGO_LINE_017);
    this->displayStr(y + 7, x_pos, SL_COLOR_LOGO_LINE_018);
    this->displayStr(y + 8, x_pos, SL_COLOR_LOGO_LINE_019);
    this->displayStr(y + 9, x_pos, SL_COLOR_LOGO_LINE_020);
    this->displayStr(y + 10, x_pos, SL_COLOR_LOGO_LINE_021);

    refresh();

    std::this_thread::sleep_for(duration);
  }
  while (x_pos > (-SL_COLOR_LOGO_MAX_LINE_SIZE));

  return 0;
}

void OutputColorLogo::displayStr(int y, int x, const std::string& str)
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
