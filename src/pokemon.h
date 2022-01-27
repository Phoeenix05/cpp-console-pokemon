#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
#include "./calc.h"

using namespace std;

namespace pokemon {

  class Pokemon {
  public: 
    string name;
    int lvl, max_hp, hp, atk, def;
    vector< moves::Move > moves;

    Pokemon() {}
    Pokemon(string n, int s[]) {
      name = n; // Asettaa pokemonin nimen
      // Antaa pokemonille random levelin (70 -> 90)
      lvl = calc::randint(90, 70);
      // Laskee pokemonin elämä pisteet
      max_hp = calc::HP(s[0], lvl);
      hp = max_hp;
      // Laskee pokemonin hyökkäyksen voiman
      atk = calc::OtherStat(s[1], lvl);
      // Laskee pokemonin puolustuksen vahvuuden
      def = calc::OtherStat(s[2], lvl);
    }

    void setMoves(moves::Move m[]) {
      // lisää liikkeet pokemonille
      for (int i = 0; i < 4; i++) moves.push_back(m[i]);
    }

    void printStats() {
      // Tulostaa pokemonin tiedot
      printf("%s   \tlvl: %d, hp: %d, atk: %d, def: %d\n", name.c_str(), lvl, hp, atk, def);
      printf("%s, %s, %s, %s\n", moves[0].str().c_str(), moves[1].str().c_str(), moves[2].str().c_str(), moves[3].str().c_str());
    }

    // Muuttaa liikkeet tekstiksi jotta ne voi tulostaa helpommin
    void printMoves() {
      for (int i = 0; i < moves.size() - 1; i++)
        printf("%s | ", moves[i].str().c_str());
      printf("%s\n", moves[moves.size()].str().c_str());
    }

  };

}

#endif