#include "Globals.h"
#include "Scene.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
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
