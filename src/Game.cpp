#include "Game.hpp"

Game::Game()
{
  scene = 0;
  tm = 0;
  show_console = false;
}

Game::~Game()
{
  if(scene != 0) delete scene;
  if(tm != 0) delete tm;
}

void Game::init()
{
  TileMap *map;
  Player *player;
  Item *item;
  Enemy *enemy;
  Town *town;

  // Initialize timer
  timer.init();

  // Loading textures
  tm = new TextureManager();
  tm->loadTexture(TEXTURE_MAP, "res/test.png");
  tm->loadTexture(TEXTURE_PLAYER, "res/link.png");
  tm->loadTexture(TEXTURE_ITEM_0, "res/apple.png");
  tm->loadTexture(TEXTURE_ENEMY_0, "res/enemy.png");
  tm->loadTexture(TEXTURE_TOWN, "res/town.png");
  tm->loadTexture(TEXTURE_BUBBLE, "res/bubble.png");

  // Loading game scene
  scene = new Scene();
  // Adding map
  map = new TileMap();
  map->init(25, 30, 8, 10, 32, 32, TEXTURE_MAP);
  scene->addEntity(map);
  // Adding town
  town = new Town();
  town->init(3, 2, TEXTURE_TOWN);
  scene->addEntity(town);
  // Adding player
  player = new Player();
  player->init(3, 8, TEXTURE_PLAYER);
  player->setCols(7);
  player->setTotalFrames(7);
  player->setWidth(16);
  player->setHeight(24);
  player->setAnimationTime(0.5f);
  scene->addEntity(player);
  // Adding item 
  item = new Item();
  item->init(ITEM_APPLE, 15, 6, TEXTURE_ITEM_0);
  scene->addEntity(item);
  // Adding enemies
  enemy = new Enemy();
  enemy->init(3, 12, TEXTURE_ENEMY_0);
  enemy->setCols(4);
  enemy->setTotalFrames(4);
  enemy->setWidth(32);
  enemy->setHeight(32);
  enemy->setAnimationTime(0.5f);
  enemy->setVelX(-70);
  scene->addEntity(enemy);
  enemy = new Enemy();
  enemy->init(12, 18, TEXTURE_ENEMY_0);
  enemy->setCols(4);
  enemy->setTotalFrames(4);
  enemy->setWidth(32);
  enemy->setHeight(32);
  enemy->setAnimationTime(0.5f);
  enemy->setVelX(-70);
  scene->addEntity(enemy);
  enemy = new Enemy();
  enemy->init(15, 5, TEXTURE_ENEMY_0);
  enemy->setCols(4);
  enemy->setTotalFrames(4);
  enemy->setWidth(32);
  enemy->setHeight(32);
  enemy->setAnimationTime(0.5f);
  enemy->setVelX(-70);
  scene->addEntity(enemy);
}

void Game::update()
{
  float dt = timer.tick();
  scene->update(dt);

  if(keys[27])
    exit(0);
  
  if(keys[186])
    show_console = true;
  else
    show_console = false;
}

void Game::render()
{
  setCamera();

  scene->render();

  startRenderGUI();
  renderConsole();
  endRenderGUI();
}

void Game::readKeyboard(int key, bool pressed)
{
  keys[key] = pressed;
}

bool Game::keyPressed(int key)
{
  return keys[key];
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
  Player* player = (Player*) scene->findEntity(ENTITY_PLAYER);

  if(player->getX() >= 200 && player->getX() <= 760)
  {
    camera_x = (int) player->getX();
  }

  if(player->getY() >= 96 && player->getY() <= 580)
  {
    camera_y = (int) player->getY();
  }

  gluLookAt(
      camera_x, camera_y+64, 150,
      camera_x, camera_y+64, 0,
      0, 1, 0
  );
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Game::renderConsole()
{
  char message[100];

  if(show_console)
  {
    glColor3f(1.0f, 1.0f, 1.0f);

    sprintf(message, "FPS: %f", timer.getFPS());
    output(0, 25, message);
    //sprintf(message, "Player position: %g,%g", player.getX(), player.getY());
    //output(0, 50, message);
    //sprintf(message, "Player is jumping: %d", player.isJumping());
    //output(0, 75, message);
    //sprintf(message, "Tile position: %d,%d", player.getRow(), player.getCol());
    //output(0, 100, message);
    //sprintf(message, "Tile type: %d", map.getTileType(player.getRow(), player.getCol()));
    //output(0, 125, message);
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

TextureManager* Game::getTextureManager()
{
  return tm;
}

Scene* Game::getScene()
{
  return scene;
}
