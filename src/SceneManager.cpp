#include "SceneManager.h"

SceneManager::SceneManager()
{
  tm = new TextureManager();
}

SceneManager::~SceneManager()
{
  delete tm;
  scenes.clear();
}

void SceneManager::render()
{
  scenes[active]->render();
}

void SceneManager::update(float dt)
{
  scenes[active]->update(dt);
}

void SceneManager::setActive(const char *active)
{
  this->active = active;
}

void SceneManager::addScene(const char *id, Scene scene)
{
  scenes.insert(pair<const char*, Scene*>(id, &scene));
}

TextureManager* SceneManager::getTextureManager()
{
  return tm;
}
