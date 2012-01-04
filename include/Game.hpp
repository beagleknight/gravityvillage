#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include <stdio.h>
#include <string.h>
#include "Timer.hpp"
#include "TileMap.hpp"
#include "Player.hpp"

class Game
{
  private:
    Timer timer;
    TileMap map;
    Player player;
    char keys[256];
    void renderFPS();
    void output(int x, int y, char *string);
    int game_width;
    int game_height;
  public:
    Game(int _game_width, int _game_height);
    ~Game();
    void readKeyboard(int key, bool pressed);
    void init();
    void render();
    void update();
};

#endif
