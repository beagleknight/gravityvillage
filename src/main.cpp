#include "Globals.h"
#include "GravityVillage.h"

int main(int argc, char **argv)
{
  GravityVillage game;
  game.init(argc, argv);
  game.run();
  return 0;
}

