#include "Game.hpp"

Game::Game(int _game_width, int _game_height)
{
  game_width = _game_width;
  game_height = _game_height;
}

Game::~Game()
{

}

void Game::readKeyboard(int key, bool pressed)
{
  keys[key] = pressed;
}

void Game::init()
{
  timer.init();
  map.init(20, 20, 8, 10, 32, 32, "res/test.png");
  player.init(96, 96, "res/link.png");
  player.setCols(7);
  player.setTotalFrames(7);
  player.setWidth(16);
  player.setHeight(24);
  player.setAnimationTime(0.5f);
}

void Game::render()
{
  map.render();
  player.render();
  renderFPS();
}

void Game::update()
{
  float dt = timer.tick();

  player.update(dt);

  if(keys[27])
    exit(0);
  else if(keys[GLUT_KEY_LEFT])
    player.setVelX(-50);
  else if(keys[GLUT_KEY_RIGHT])
    player.setVelX(50);
  else
    player.setVelX(0);
}

void Game::renderFPS()
{
  char fps[100];
  sprintf(fps, "FPS: %f", timer.getFPS());
  glColor3f(1.0f, 1.0f, 1.0f);
  output(0, (game_height / 2) - 25, fps);
}

void Game::output(int x, int y, char *string)
{
  int len, i;
  void *font = GLUT_BITMAP_TIMES_ROMAN_24;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}
