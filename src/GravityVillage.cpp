#include "GravityVillage.h"

GravityVillage::GravityVillage()
{
  game = Game::getInstance();
}

GravityVillage::~GravityVillage()
{

}

void GravityVillage::init(int argc, char **argv)
{
  game->init(argc, argv);

  // game initialization goes here

  game->getSceneManager()->getTextureManager()->loadTexture(TextureManager::TEX_PLAYER,"res/bub.png");
  game->getSceneManager()->getTextureManager()->loadTexture(TextureManager::TEX_MAP,"res/blocks.png");
  game->getSceneManager()->addScene("main", Scene());
  game->getSceneManager()->setActive("main");
}

void GravityVillage::run()
{
  game->run();
}
