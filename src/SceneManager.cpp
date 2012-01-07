#include "SceneManager.hpp"

SceneManager::SceneManager()
{
  active = -1;
  scenes = std::vector<Scene*> (100);
}

SceneManager::~SceneManager()
{
  scenes.clear();
}

void SceneManager::addScene(int id, Scene *scene)
{
  scenes[id] = scene;
}

Scene* SceneManager::getActive()
{
  return scenes[active];
}

void SceneManager::setActive(int id)
{
  active = id;
}

void SceneManager::update(float dt)
{
  scenes[active]->update(dt);
}

void SceneManager::render()
{
  scenes[active]->render();
}
