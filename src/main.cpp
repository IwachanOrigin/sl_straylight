

#include <ncurses.h>

int main(int argc, char* argv[])
{
  // initialize screen
  // sets up memory and clears the screen
  initscr();

  noecho(); // hide key input

  curs_set(0); // hide cursor
  
  mvprintw(12, 30, "hello world!");

  while (true)
  {
    int ch = getch();
    if (ch == 'q')
    {
      break;
    }
  }
  

  // end window.
  endwin();
  
  return 0;
}
