#include "Game.h"

Game::Game()
{
  sm = new SceneManager();
  sm->getTextureManager()->loadTexture("bub","bub.png");
  //sm->getTextureManager()->loadTexture("blocks","blocks.png");
}

Game::~Game()
{
  delete sm;
}

void Game::init()
{
  sm->addScene("main", Scene());
  sm->setActive("main");
}

void Game::render()
{
  sm->render();
}

void Game::update(float dt)
{
  sm->update(dt);
}

SceneManager* Game::getSceneManager()
{
  return sm;
}
