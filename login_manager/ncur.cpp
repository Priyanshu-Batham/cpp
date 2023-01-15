#include <ncurses.h>
#include <string.h>
#include <signal.h>

// SIGWINCH is called when the window is resized.
void handle_winch(int sig){
  signal(SIGWINCH, SIG_IGN);

  // Reinitialize the window to update data structures.
  endwin();
  initscr();
  refresh();
  clear();

  char tmp[128];
  //sprintf(tmp, "%dx%d", COLS, LINES);
  //sprintf(tmp,"Welcome to National Post Graduate College");
  
  // Approximate the center
  int x = COLS / 2 - strlen(tmp) / 2;
  int y = LINES / 2 - 1;

  mvaddstr(y, x, tmp);
  refresh();

  signal(SIGWINCH, handle_winch);
}

int main(int argc, char *argv[]){
  initscr();
  // COLS/LINES are now set

  signal(SIGWINCH, handle_winch);

  while(getch() != 27){
    printw("Welcome To National Post Graduate College");
  }

  endwin();

  return(0);
}
