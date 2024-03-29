
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
  int one_start_pos_002 = SL_COLOR_LOGO_002_ONE_POS;
  int b_start_pos_002 = one_start_pos_002 + SL_COLOR_LOGO_PARTS_RED.size();

  int two_start_pos_002 = SL_COLOR_LOGO_002_TWO_POS;
  int c_start_pos_002 = two_start_pos_002 + SL_COLOR_LOGO_PARTS_RED.size();

  int three_start_pos_002 = SL_COLOR_LOGO_002_THREE_POS;
  int d_start_pos_002 = three_start_pos_002 + SL_COLOR_LOGO_PARTS_RED.size();

  int one_start_pos_003 = SL_COLOR_LOGO_003_ONE_POS;
  int b_start_pos_003 = one_start_pos_003 + SL_COLOR_LOGO_PARTS_RED.size();

  int two_start_pos_003 = SL_COLOR_LOGO_003_TWO_POS;
  int c_start_pos_003 = two_start_pos_003 + SL_COLOR_LOGO_PARTS_RED.size();

  int three_start_pos_003 = SL_COLOR_LOGO_003_THREE_POS;
  int d_start_pos_003 = three_start_pos_003 + SL_COLOR_LOGO_PARTS_RED.size();

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
    // line2-1
    this->displayStr(y - 9, x_pos + one_start_pos_002, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + b_start_pos_002, SL_COLOR_LOGO_LINE_002_B);
    // line2-2
    attron(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + two_start_pos_002, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + c_start_pos_002, SL_COLOR_LOGO_LINE_002_C);
    // line2-3
    attron(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + three_start_pos_002, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 9, x_pos + d_start_pos_002, SL_COLOR_LOGO_LINE_002_D);

    this->displayStr(y - 8, x_pos, SL_COLOR_LOGO_LINE_003_A);
    attron(COLOR_PAIR(1));
    // line3-1
    this->displayStr(y - 8, x_pos + one_start_pos_003, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + b_start_pos_003, SL_COLOR_LOGO_LINE_003_B);
    // line3-2
    attron(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + two_start_pos_003, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + c_start_pos_003, SL_COLOR_LOGO_LINE_003_C);
    // line3-3
    attron(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + three_start_pos_003, SL_COLOR_LOGO_PARTS_RED);
    attroff(COLOR_PAIR(1));
    this->displayStr(y - 8, x_pos + d_start_pos_003, SL_COLOR_LOGO_LINE_003_D);

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

    if (m_flushON)
    {
      if (x_pos % 2 == 0)
      {
        flash();
      }
    }

    refresh();

    std::this_thread::sleep_for(duration);
  }
  while (x_pos > (-SL_COLOR_LOGO_MAX_LINE_SIZE));

  refresh();

  return 0;
}

