
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef __linux__
#include <curses.h>
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

  // init
  init_curses();

  // clear background color.
  bkgd(COLOR_PAIR(1));
  // subwin(WINDOW*, int nlines, int ncols, int begin_y, int begin_x)
  messagebar = subwin(stdscr,1,80,1,1);
  scrollmessage = subwin(stdscr,1,80,2,3);
  printw("ESC quits.");
  refresh();

  do
  {
    key = getch();
    // clear
    werase(messagebar);
    // refresh
    wrefresh(messagebar);
    wprintw(messagebar,"I am Message bar.");

    // clear
    werase(scrollmessage);
    // refresh
    wrefresh(scrollmessage);
    wprintw(scrollmessage, "I am scroll message.");
    // The touchwin func raises a flag in the WINDOW structure to inform the refresh func that all lines have changed.
    touchwin(stdscr);
    refresh();

  } while (key!=ESC);

  delwin(scrollmessage);
  delwin(messagebar);
  endwin();
  return 0;
}
