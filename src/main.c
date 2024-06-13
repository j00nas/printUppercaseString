#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include "drawString.h"
#ifndef _screen_h_
#define _Screen_h_
#endif

int startPrinting(char *wordToPrint, int wordLength){
  Screen gameScreen = initScreen();
  drawBigString(wordToPrint, &gameScreen, wordLength);
  return 0;
}

int main(int argc, char *argv[]) {
  char wordToPrint[255];
  if (argc == 1){
    printf("Need one argument (String to print).\n");
    return 1;
  }else if (argc > 2){
    printf("Too many arguments.\n");
    return 1;
  };
 
  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);
 
  int printWordStatus = startPrinting(argv[1], (int)strlen(argv[1]));
  
  endwin();
  return printWordStatus;
};
