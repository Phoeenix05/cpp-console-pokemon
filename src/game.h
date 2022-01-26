#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <unistd.h>
#include "./pokemon.h"

using namespace std;

namespace game {

  class Game {
  public:
    Game(string p_name, pokemon::Pokemon p, string c_name, pokemon::Pokemon c) {
      printf("\033c"); // Puhdistaa näytön

      bool running = true;

      while (running) {
        printf("\033c"); // Puhdistaa näytön
        
        // Tulostaa pelin tiedot
        printf("\033[34m%s\033[0m\n", c_name.c_str());
        printf("%s   \t%d / %d\n\n", c.name.c_str(), c.hp, c.max_hp);
        printf("\033[34m%s\033[0m\n", p_name.c_str());
        printf("%s   \t%d / %d\n\n", p.name.c_str(), p.hp, p.max_hp);
        p.printMoves();
        printf("\n\033[31mValitse liike numeroilla 1 - 4\033[0m\n");

        // Saa pelaajalta numero 1 - 4 while loop jatkuu jos numero ei ole 1 - 4 
        // tai jos syötetään kirjain
        int idx = 0;
        while (true) {
          while (!(cin >> idx)) {
            cin.clear();
            while (cin.get() != '\n');
          }
          if (idx > 0 && idx < 5) break;
        }

        c.hp -= calc::damage(p.lvl, p.moves[calc::randint(3)].power, p.atk, c.def);
        p.hp -= calc::damage(c.lvl, c.moves[calc::randint(3)].power, c.atk, p.def);

        if (p.hp <= 0) {
          printf("\033[34m%s\033[0m voitti!\n", c_name.c_str());
          running = false;
        } else if (c.hp <= 0) {
          printf("\033[34m%s\033[0m voitti!\n", p_name.c_str());
          running = false;
        }
      }
    }
  };

}

#endif