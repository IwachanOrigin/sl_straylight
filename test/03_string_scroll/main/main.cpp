
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
  messagebar = subwin(stdscr,1,80,23,1);
  scrollmessage = subwin(stdscr,1,80,0,0);
  // move the cursor
  move(2,1);
  printw("ESC quits.");
  refresh();

  do
  {
    key=getch();
    // clear
    werase(messagebar);
    // refresh
    wrefresh(messagebar);
    wprintw(messagebar,"You haven't selected any item.");

    // clear
    werase(scrollmessage);
    // refresh
    wrefresh(scrollmessage);
    wprintw(scrollmessage, "Message");

  } while (key!=ESC);

  delwin(scrollmessage);
  delwin(messagebar);
  endwin();
  return 0;
}
