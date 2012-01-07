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
#include "TextureManager.hpp"
#include "Scene.hpp"

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
    Scene *scene;
    TextureManager *tm;
    Game();
    ~Game();
    void init();
    void update();
    void render();
    void readKeyboard(int key, bool pressed);
    bool keyPressed(int key);
    void setCamera();
    void startRenderGUI();
    void endRenderGUI();
    void setWindowWidth(int _window_w);
    int getWindowWidth();
    void setWindowHeight(int _window_h);
    int getWindowHeight();
    void drawAxis();
    TextureManager* getTextureManager();
    Scene* getScene();
};

#endif
