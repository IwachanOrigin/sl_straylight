
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef __linux__
#include <curses.h>
#include <unistd.h>
#endif

#define ENTER 10
#define ESC 27

void init_curses()
{
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  init_pair(2,COLOR_BLUE,COLOR_WHITE);
  init_pair(3,COLOR_RED,COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
}

int main(int argc, char *argv[])
{
  int key;
  WINDOW *messagebar = nullptr;
  WINDOW *scrollmessage = nullptr;
  int width = 0;
  int height = 0;

  // init
  init_curses();

  // clear background color.
  bkgd(COLOR_PAIR(1));

  // Get max size of height, width
  getmaxyx(stdscr, height, width);
  // Set max width
  int x_pos = width;

  // subwin(WINDOW*, int nlines, int ncols, int begin_y, int begin_x)
  printw("ESC quits.");
  refresh();

  do
  {
    // clear
    erase();
    mvwprintw(stdscr, 2, x_pos, "I am scroll message.");
    x_pos--;
    // The touchwin func raises a flag in the WINDOW structure to inform the refresh func that all lines have changed.
    touchwin(stdscr);
    refresh();

    usleep(40000);

  } while (key != ESC && x_pos > 0);

  endwin();
  return 0;
}
