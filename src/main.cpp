

#include <ncurses.h>

int main(int argc, char* argv[])
{
  // initialize screen
  // sets up memory and clears the screen
  initscr();

  noecho(); // hide key input

  curs_set(0); // hide cursor

  keypad(stdscr, TRUE);

  mousemask(ALL_MOUSE_EVENTS, NULL);
  MEVENT e;
  int px = 2;
  
  while (true)
  {
    int ch = getch();
    if (ch == 'q') {
      break;
    }
    if (ch == KEY_MOUSE) {
      if (getmouse(&e) == OK) {
        clear();
        px = e.x;
        if (px < 2) { px = 2; }
        if (px > 77) { px = 77; }
        mvprintw(23, px -2, "-----");
        refresh();
      }
    }
  }
  

  // end window.
  endwin();
  
  return 0;
}
