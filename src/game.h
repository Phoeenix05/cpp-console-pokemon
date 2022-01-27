#ifndef GAME_H
#define GAME_H

#include <string>
#include <fstream>
#include <memory>
#include "./pokemon.h"

using namespace std;

namespace game {

  void writeFile(string name, pokemon::Pokemon pokemon) {
    ofstream f;
    f.open("./text.txt"); // Avaa tiedoston (luo jos ei ole olemassa)
    f << "Onnea " << name << " voitit!\n" << pokemon.name; // Kirjoittaa
    f.close(); // Sulkee tiedoston
  }

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

        // Miinustaa tehdyn damagen pokemonien elämä pisteistä
        c.hp -= calc::damage(p.lvl, p.moves[calc::randint(3)].power, p.atk, c.def);
        p.hp -= calc::damage(c.lvl, c.moves[calc::randint(3)].power, c.atk, p.def);

        // Tarkastaa onko jomman kumman pokemonin hp 0
        // Jos nolla lopettaa while loopin
        if (c.hp <= 0) {
          printf("\033[34m%s\033[0m voitti!\n", p_name.c_str());
          // Kirjoittaa tiedostoon jos voitit
          writeFile(p_name, p);
          running = false;
        } else if (p.hp <= 0) {
          printf("\033[34m%s\033[0m voitti!\n", c_name.c_str());
          running = false;
        }
      }
    }
  };

}

#endif