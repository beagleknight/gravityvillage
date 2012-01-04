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
    int window_w;
    int window_h; 
  public:
    Game();
    ~Game();
    void readKeyboard(int key, bool pressed);
    void init();
    void setCamera();
    void render();
    void update();
    void startRenderGUI();
    void endRenderGUI();
    void setWindowWidth(int _window_w);
    int getWindowWidth();
    void setWindowHeight(int _window_h);
    int getWindowHeight();
};

#endif
