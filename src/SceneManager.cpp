#include "SceneManager.hpp"
#include "Game.hpp"

extern Game game;

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

int SceneManager::getActiveId()
{
  return active;
}

void SceneManager::setActive(int id)
{
  active = id;
  game.resetKeyboard();
}

void SceneManager::update(float dt)
{
  scenes[active]->update(dt);
}

void SceneManager::render()
{
  scenes[active]->render();
}

void SceneManager::renderGUI()
{
  scenes[active]->renderGUI();
}
