#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include <stdio.h>
#include <string.h>
#include <vector>
#include "Timer.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Enemy.hpp"
#include "Town.hpp"

class Game
{
  private:
    Timer timer;
    char keys[256];
    void renderConsole();
    void output(int x, int y, char *string);
    int window_w;
    int window_h; 
    bool show_console;
  public:
    TileMap map;
    Player player;
    Item item;
    Town town;
    std::vector<Enemy*> enemies;
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
    void drawAxis();
};

#endif
