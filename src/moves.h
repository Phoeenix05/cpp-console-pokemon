#ifndef MOVES_H
#define MOVES_H

#include <string>

using namespace std;

namespace moves {

  class Move {
  public:
    int power;
    string name;

    /**
     * @brief Construct a new Move object
     *
     * @param n Move : name
     * @param pwr Move's strength (power)
     */
    Move(string n, int pwr) { 
      name = n; // Asettaa liikkeen nimen
      power = pwr; // Asettaa liikkeen tehon
    }
    
    string str() {
      // Palauttaa liikkeen nimen ja voiman yhdessä
      return to_string(power) + " " + name;
    }
  };

}

#endif