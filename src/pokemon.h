#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "./calc.h"

using namespace std;

namespace pokemon {

  class Pokemon {
  public: 
    string name;
    int lvl, hp, atk, def;

    Pokemon(string name_, int stats[]) {
      name = name_;
      lvl = calc::randint(90, 70);
      hp = calc::HP(stats[0], lvl);
      atk = calc::OtherStat(stats[1], lvl);
      def = calc::OtherStat(stats[2], lvl);
    }

    void printStats() {
      cout << lvl << ' ' << hp << ' ' << atk << ' ' << def << endl;
    }

  };

}

#endif