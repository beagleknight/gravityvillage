#include "Game.hpp"

Game::Game()
{

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

  item.init(256, 96, "res/apple.png");
  item.setScale(0.5f);

  enemy.init(512, 96, "res/enemy.png");
  enemy.setCols(4);
  enemy.setTotalFrames(4);
  enemy.setWidth(32);
  enemy.setHeight(32);
  enemy.setAnimationTime(0.5f);
  enemy.setVelX(-70);
}

void Game::setCamera()
{
  GLfloat aspectRatio;
  aspectRatio = (GLfloat) window_w / (GLfloat) window_h;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(90,aspectRatio,1,1000);

  gluLookAt(
      player.getX(), player.getY(), 100,
      player.getX(), player.getY(), 0,
      0, 1, 0
  );
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Game::render()
{
  setCamera();

  map.render();
  player.render();
  item.render();
  enemy.render();

  startRenderGUI();
  renderFPS();
  endRenderGUI();
}

void Game::update()
{
  float dt = timer.tick();

  player.update(dt);
  item.update(dt);
  enemy.update(dt);

  if(player.collision(&item))
  {
    item.setAlive(false);
  }

  if(player.collision(&enemy))
  {
    exit(0);
  }

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
  output(0, 25, fps);
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

void Game::startRenderGUI()
{
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);

	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();

	// reset matrix
	glLoadIdentity();

	// set a 2D orthographic projection
	gluOrtho2D(0, window_w, window_h, 0);

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void Game::endRenderGUI()
{
  glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void Game::setWindowWidth(int _window_w)
{
  window_w = _window_w;
}

int Game::getWindowWidth()
{
  return window_w; 
}

void Game::setWindowHeight(int _window_h)
{
  window_h = _window_h;
}

int Game::getWindowHeight()
{
  return window_h;
}
