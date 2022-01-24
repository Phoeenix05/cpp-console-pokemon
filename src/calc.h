#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <math.h>

using namespace std;

namespace calc {

  int randint(int high, int low = 0) { return rand() % ( high - low + 1 ) + low; }
  float randf(float high, float low = 0.0) {
    return roundf((((high - low) * ((float) rand() / RAND_MAX)) + 0.85) * 100) / 100;
  }
    
  /**
   * @brief Calculates the damage pokemon will deal to opponent
   * 
   * @param lvl Pokemon' lvl
   * @param pwr Base power of a move
   * @param atk Pokemon' attack
   * @param def Pokemon' defense
   * @return float 
   */
  float damage(int lvl, int pwr, int atk, int def) {
    return (float) ((((2 * lvl) / 5 + 2) * pwr * (atk / def)) / 50 + 2) * randf(1.0, 0.85);
  }


  int HP(int base, int lvl, int iv = randint(15), int ev = randint(100)) {
    return (int) floor((((base + iv) * 2 + floor(ceil(sqrt(ev)) / 4)) * lvl) / 100) + lvl + 5;
  }

  int OtherStat(int base, int lvl, int iv = randint(15), int ev = randint(100)) {
    return (int) floor((((base + iv) * 2 + floor(ceil(sqrt(ev)) / 4)) * lvl) / 100) + 5;
  }

} 

#endif