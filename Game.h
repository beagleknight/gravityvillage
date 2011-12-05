#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include "Globals.h"
#include "Scene.h"
#include "SceneManager.h"

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
    void init();
  private:
    Game();
    Game(Game const&);
    void operator=(Game const&);
    ~Game();
    SceneManager *sm;
};
#endif
