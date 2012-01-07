#include "Game.hpp"

Game::Game()
{
  tm = 0;
  sm = 0;
  show_console = false;
  gameover = false;
}

Game::~Game()
{
  if(tm != 0) delete tm;
  if(sm != 0) delete sm;
}

void Game::init()
{
  Scene *scene;
  Level *level;

  TextLabel *text_label;
  TileMap *map;
  Player *player;
  Item *item;
  Enemy *enemy;
  Town *town;

  // Initialize timer
  timer.init();
  // Initializing managers
  tm = new TextureManager();
  sm = new SceneManager();

  // Loading textures
  tm->loadTexture(TEXTURE_MAP, "res/textures/test.png");
  tm->loadTexture(TEXTURE_PLAYER, "res/textures/link.png");
  tm->loadTexture(TEXTURE_ITEM_0, "res/textures/apple.png");
  tm->loadTexture(TEXTURE_ENEMY_0, "res/textures/enemy.png");
  tm->loadTexture(TEXTURE_TOWN, "res/textures/town.png");
  tm->loadTexture(TEXTURE_BUBBLE, "res/textures/bubble.png");

  // Loading start scene
  scene = new Scene();
  text_label = new TextLabel(255, 100, "Gravity Village");
  scene->addGUIElement(text_label);
  text_label = new TextLabel(210, 400, "- Press SPACE to start -");
  scene->addGUIElement(text_label);
  sm->addScene(SCENE_START, scene);

  // Loading game scene
  level = new Level("res/levels/level0.xml");
  level->init();
  sm->addScene(SCENE_GAME, level);

  // Loading end scene
  scene = new Scene();
  text_label = new TextLabel(255, 100, "GAME OVER");
  scene->addGUIElement(text_label);
  text_label = new TextLabel(220, 400, "- Press SPACE to continue -");
  scene->addGUIElement(text_label);
  sm->addScene(SCENE_END, scene);

  // Set active scene
  sm->setActive(SCENE_START);
}

void Game::update()
{
  float dt = timer.tick();
  sm->update(dt);

  if(keys[27])
    exit(0);

  if(sm->getActiveId() == SCENE_START || sm->getActiveId() == SCENE_END)
  {
    if(keys[32])
    {
      gameover = false;
      sm->setActive(SCENE_GAME);
      ((Level*) sm->getActive())->init();
    }
  }
  else // game scene is active
  {
    if(gameover)
    {
      sm->setActive(SCENE_END);
    }
  }
  
  if(keys[186])
    show_console = true;
  else
    show_console = false;
}

void Game::render()
{
  setCamera();
  sm->render();

  startRenderGUI();
  sm->renderGUI();
  endRenderGUI();
}

void Game::readKeyboard(int key, bool pressed)
{
  keys[key] = pressed;
}

void Game::resetKeyboard()
{
  for(int i = 0; i < 256; i++)
  {
    keys[i] = 0;
  }
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
  Player* player = (Player*) sm->getActive()->findEntity(ENTITY_PLAYER);
  if(player != 0)
  {
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
  }
    
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
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

SceneManager* Game::getSceneManager()
{
  return sm;
}

void Game::setGameOver(bool _gameover)
{
  gameover = _gameover;
}
