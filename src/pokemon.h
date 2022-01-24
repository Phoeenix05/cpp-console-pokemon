#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "./calc.h"
#include "../util/util.h"

using namespace std;

namespace pokemon {

  class Pokemon {
  public: 
    string name;
    int lvl, hp, atk, def;

    Pokemon(string n, int s[]) {
      name = n;
      lvl = calc::randint(90, 70);
      hp = calc::HP(s[0], lvl);
      atk = calc::OtherStat(s[1], lvl);
      def = calc::OtherStat(s[2], lvl);
    }

    void printStats() {
      cout << lvl << ' ' << hp << ' ' << atk << ' ' << def << endl;
    }

  };

}

#endif