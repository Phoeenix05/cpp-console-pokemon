#include <iostream>
#include <string>
#include "./src/moves.h"
#include "./src/pokemon.h"
#include "./util/util.h"

using namespace std;

int main(int argc, char** argv){
  srand (time(NULL)); // Init random seed

  pokemon::Pokemon p1("Pikachu", (int[]) {35, 55, 40});
  p1.printStats();

}
