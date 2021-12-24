

#include <unistd.h>
#include <ncurses.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char *car_up= "  ___  ";
  char *car_mp= "_|[ ]|_";
  char *car_dp= "-O---O-";
  char *blank = " ";
  int car_len = strlen(car_dp);
  int dir = +1;
  int pos = 1;
  int ground = 20;

  initscr();
  clear();

  while(1){
    move(ground-2, pos);
    addstr(car_up);
    move(ground-1, pos);
    addstr(car_mp);
    move(ground, pos);
    addstr(car_dp);
    refresh();
    if(pos >= (COLS-car_len))
      break;
    usleep(50000);
    move(18, pos);
    addstr(blank);
    move(19, pos);
    addstr(blank);
    move(20, pos);
    addstr(blank);
    pos += dir;
  }

  endwin();

  return 0;
}
