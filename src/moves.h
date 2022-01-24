#ifndef MOVES_H
#define MOVES_H

#include <string>

using namespace std;

namespace moves {

  class Move {
    int power;
    string name;
    string description;

    /**
     * @brief Construct a new Move object
     *
     * @param n Move : name
     * @param pwr Move's strength (power)
     * @param desc Move's description
     */
    Move(string n, int pwr, string desc) { 
      name = n;
      power = pwr; 
      description = desc;
    }
  };

}

#endif