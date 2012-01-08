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
#include "SceneManager.hpp"
#include "TextLabel.hpp"
#include "Level.hpp"
#include "SoundManager.hpp"

class Game
{
  private:
    Timer timer;
    char keys[256];
    void output(int x, int y, char *string);
    int window_w;
    int window_h; 
    bool show_console;
    bool gameover;
    int player_lives;
  public:
    TextureManager *tm;
    SceneManager *sm;
    SoundManager *sdm;
    Game();
    ~Game();
    void init(int argc, char** argv);
    void update();
    void render();
    void readKeyboard(int key, bool pressed);
    void resetKeyboard();
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
    SceneManager* getSceneManager();
    SoundManager* getSoundManager();
    void setGameOver(bool _gameover);
};

#endif
