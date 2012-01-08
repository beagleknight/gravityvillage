#include "Game.hpp"

Game::Game()
{
  tm = 0;
  sm = 0;
  sdm = 0;
  show_console = false;
  gameover = false;
  victory = false;
  player_lives = 2;
}

Game::~Game()
{
  if(tm != 0) delete tm;
  if(sm != 0) delete sm;
  if(sdm != 0) delete sdm;
}

void Game::init(int argc, char** argv)
{
  // Creating managers
  tm = new TextureManager();
  sm = new SceneManager();
  sdm = new SoundManager();

  // Initialize timer
  timer.init();
  // Initializing Sound Manager
  sdm->init(argc, argv);

  // Loading textures
  tm->loadTexture(TEXTURE_MAP, "res/textures/test.png");
  tm->loadTexture(TEXTURE_PLAYER, "res/textures/link.png");
  tm->loadTexture(TEXTURE_ITEM_0, "res/textures/apple.png");
  tm->loadTexture(TEXTURE_ENEMY_0, "res/textures/enemy.png");
  tm->loadTexture(TEXTURE_TOWN, "res/textures/town.png");
  tm->loadTexture(TEXTURE_BUBBLE, "res/textures/bubble.png");
  tm->loadTexture(TEXTURE_COIN, "res/textures/coin.png");

  // Loading sounds
  sdm->addSound(SOUND_MARIO_OST, "res/sounds/mario.wav");
  sdm->addSound(SOUND_JUMP, "res/sounds/jump.wav");
  sdm->addSound(SOUND_PICK_ITEM, "res/sounds/pick_item.wav");
  sdm->addSound(SOUND_PICK_QUEST, "res/sounds/pick_quest.wav");

  // Loading start scene
  sm->addScene(SCENE_START, new Level("res/levels/start.xml"));
  // Loading game scene
  sm->addScene(SCENE_GAME, new Level("res/levels/level0.xml"));
  // Loading end scene
  sm->addScene(SCENE_END, new Level("res/levels/end.xml"));
  // Loading victory scene
  sm->addScene(SCENE_VICTORY, new Level("res/levels/victory.xml"));

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
      player_lives = 2;
      sm->setActive(SCENE_GAME);
      sdm->playMusic(SOUND_MARIO_OST);
      ((Level*) sm->getActive())->init();
      ((Player*)((Level*) sm->getActive())->findEntity(ENTITY_PLAYER))->setLives(player_lives);
    }
  }
  else // game scene is active
  {
    if(gameover)
    {
      player_lives--;
      if(player_lives < 0)
      {
        sm->setActive(SCENE_END);
      }
      else
      {
        gameover = false;
        ((Level*) sm->getActive())->init();
        ((Player*)((Level*) sm->getActive())->findEntity(ENTITY_PLAYER))->setLives(player_lives);
        sm->setActive(SCENE_GAME);
      }
    }
    else if(victory)
    {
      sm->setActive(SCENE_VICTORY);
    }
  }
  
  if(keys[GLUT_KEY_F1])
    ((Level*)sm->getActive())->init();

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

SoundManager* Game::getSoundManager()
{
  return sdm;
}

void Game::setGameOver(bool _gameover)
{
  gameover = _gameover;
}

void Game::setVictory(bool _victory)
{
  victory = _victory;
}
