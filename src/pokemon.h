#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
#include <curses.h>
#include "./calc.h"
#include "../util/util.h"

using namespace std;

namespace pokemon {

  class Pokemon {
  public: 
    string name;
    int lvl, hp, atk, def;
    vector< moves::Move > moves;

    Pokemon(string n, int s[]) {
      name = n;
      lvl = calc::randint(90, 70);
      hp = calc::HP(s[0], lvl);
      atk = calc::OtherStat(s[1], lvl);
      def = calc::OtherStat(s[2], lvl);
    }

    void setMoves(moves::Move m[]) {
      for (int i = 0; i < 4; i++) moves.push_back(m[i]);
    }

    void printStats() {
      printw("%s   \tlvl: %d, hp: %d, atk: %d, def: %d\n", name.c_str(), lvl, hp, atk, def);
      printw("%s, %s, %s, %s\n", moves[0].str().c_str(), moves[1].str().c_str(), moves[2].str().c_str(), moves[3].str().c_str());
      refresh();
    }

  };

}

#endif