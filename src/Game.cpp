#include "Game.hpp"

Game::Game()
{
  show_console = false;
}

Game::~Game()
{
  enemies.clear();
}

void Game::readKeyboard(int key, bool pressed)
{
  keys[key] = pressed;
}

void Game::init()
{
  timer.init();

  map.init(25, 30, 8, 10, 32, 32, "res/test.png");

  player.init(3, 8, "res/link.png");
  player.setCols(7);
  player.setTotalFrames(7);
  player.setWidth(16);
  player.setHeight(24);
  player.setAnimationTime(0.5f);

  item.init(ITEM_APPLE, 15, 6, "res/apple.png");

  Enemy *enemy;

  enemy = new Enemy();
  enemy->init(3, 12, "res/enemy.png");
  enemy->setCols(4);
  enemy->setTotalFrames(4);
  enemy->setWidth(32);
  enemy->setHeight(32);
  enemy->setAnimationTime(0.5f);
  enemy->setVelX(-70);
  enemies.push_back(enemy);

  enemy = new Enemy();
  enemy->init(12, 18, "res/enemy.png");
  enemy->setCols(4);
  enemy->setTotalFrames(4);
  enemy->setWidth(32);
  enemy->setHeight(32);
  enemy->setAnimationTime(0.5f);
  enemy->setVelX(-70);
  enemies.push_back(enemy);

  enemy = new Enemy();
  enemy->init(15, 5, "res/enemy.png");
  enemy->setCols(4);
  enemy->setTotalFrames(4);
  enemy->setWidth(32);
  enemy->setHeight(32);
  enemy->setAnimationTime(0.5f);
  enemy->setVelX(-70);
  enemies.push_back(enemy);

  town.init(3, 2, "res/town.png");
}

void Game::setCamera()
{
  GLfloat aspectRatio;
  aspectRatio = (GLfloat) window_w / (GLfloat) window_h;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(90,aspectRatio,1,1000);

  static float camera_x;
  static float camera_y;

  if(player.getX() >= 200 && player.getX() <= 760)
  {
    camera_x = (int) player.getX();
  }

  if(player.getY() >= 96 && player.getY() <= 580)
  {
    camera_y = (int) player.getY();
  }

  gluLookAt(
      camera_x, camera_y+64, 150,
      camera_x, camera_y+64, 0,
      0, 1, 0
  );
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Game::render()
{
  setCamera();

  map.render();
  town.render();
  player.render();
  item.render();

  for(int i = 0; i < enemies.size(); i++)
  {
    enemies[i]->render();
  }

  startRenderGUI();
  renderConsole();
  endRenderGUI();
}

void Game::update()
{
  float dt = timer.tick();

  player.update(dt);
  item.update(dt);
  town.update(dt);

  for(int i = 0; i < enemies.size(); i++)
  {
    enemies[i]->update(dt);
  }

  if(keys[27])
    exit(0);
  
  if(keys[186])
    show_console = true;
  else
    show_console = false;

  if(keys[GLUT_KEY_LEFT])
    player.move_left();
  else if(keys[GLUT_KEY_RIGHT])
    player.move_right();
  else
    player.halt();

  if(keys[32])
    player.jump();
}

void Game::renderConsole()
{
  char message[100];

  if(show_console)
  {
    glColor3f(1.0f, 1.0f, 1.0f);

    sprintf(message, "FPS: %f", timer.getFPS());
    output(0, 25, message);
    sprintf(message, "Player position: %g,%g", player.getX(), player.getY());
    output(0, 50, message);
    sprintf(message, "Player is jumping: %d", player.isJumping());
    output(0, 75, message);
    sprintf(message, "Tile position: %d,%d", player.getRow(), player.getCol());
    output(0, 100, message);
    sprintf(message, "Tile type: %d", map.getTileType(player.getRow(), player.getCol()));
    output(0, 125, message);
  }
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

void Game::drawAxis()
{
  glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(100, 0, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 100, 0);
  glEnd();
}
