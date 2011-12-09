#ifndef CLASS_GRAVITY_VILLAGE_H
#define CLASS_GRAVITY_VILLAGE_H

#include "Globals.h"
#include "Game.h"

class GravityVillage
{
  private:
    Game *game;
  public:
    GravityVillage();
    ~GravityVillage();
    void init(int, char**);
    void run();
};

#endif
