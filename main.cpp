#include <iostream>
#include <string>
#include "./src/moves.h"
#include "./src/pokemon.h"
#include "./src/calc.h"
#include "./src/game.h"

using namespace std;

void init() {
  printf("\033c"); // Puhdistaa näytön
  // Initialisoi random numero funktion
  srand (time(NULL));
}

int main(int argc, char** argv){
  init();
  
  // Lista pokemoneista
  pokemon::Pokemon pokemons[] = {
    pokemon::Pokemon("Pidgey", (int[]) {40, 45, 40}), pokemon::Pokemon("Jigglypuff", (int[]) {115, 45, 20}),
    pokemon::Pokemon("Exeggcute", (int[]) {60, 40, 80}), pokemon::Pokemon("Pikachu", (int[]) {35, 55, 40}),
    pokemon::Pokemon("Horsea", (int[]) {30, 40, 70}), pokemon::Pokemon("Eevee", (int[]) {55, 55, 50}),
    pokemon::Pokemon("Dratini", (int[]) {41, 64, 45})
  };
  int len_p = (sizeof(pokemons) / sizeof(*pokemons)) - 1;

  // Lista pokemonien liikkeistä
  moves::Move moves[] = {
    moves::Move("Headbutt", 70), moves::Move("Double Hit", 70),
    moves::Move("Hyper Beam", 150), moves::Move("Hyper Fang", 80), moves::Move("Mega Puch", 80),
    moves::Move("Multi-Attack", 120), moves::Move("Tackle", 60), moves::Move("Tail Slap", 65),
    moves::Move("Scratch", 55), moves::Move("Karate Chop", 55), moves::Move("Slash", 70)
  };
  int len_m = (sizeof(moves) / sizeof(*moves)) - 1;

  // Antaa pelaajalle ja tietokoneelle random pokemonit
  pokemon::Pokemon player = pokemons[calc::randint(len_p, 0)];
  player.setMoves((moves::Move[]) {
    moves[calc::randint(len_m, 0)], moves[calc::randint(len_m, 0)], moves[calc::randint(len_m, 0)], moves[calc::randint(len_m, 0)]
  });
  pokemon::Pokemon computer = pokemons[calc::randint(len_p, 0)];
  computer.setMoves((moves::Move[]) {
    moves[calc::randint(len_m, 0)], moves[calc::randint(len_m, 0)], moves[calc::randint(len_m, 0)], moves[calc::randint(len_m, 0)]
  });
  

  // Kysyy pelaajalta nimen ja tallentaa sen 
  string name;
  printf("Kirjoita nimesi\n");
  cin >> name;

  // Aloittaa pelin
  game::Game g(name, player, "Computer", computer);

}
