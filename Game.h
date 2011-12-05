#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include "Globals.h"

class Game
{
  public:
    static Game& getInstance()
    {
      static Game instance;
      return instance;
    }
    void render();
    void update(float);
  private:
    Game();
    Game(Game const&);
    void operator=(Game const&);
    ~Game();
};
#endif
