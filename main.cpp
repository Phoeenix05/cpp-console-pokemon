#include <iostream>
#include <string>
#include <curses.h>

#include "./src/moves.h"
#include "./src/pokemon.h"
#include "./util/util.h"

using namespace std;

void init() {
  srand (time(NULL)); // Init random seed
  initscr();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  scrollok(stdscr, TRUE);
}

int main(int argc, char** argv){
  init();

  pokemon::Pokemon p1("Pikachu", (int[]) {35, 55, 40});
  p1.printStats();
  
}
