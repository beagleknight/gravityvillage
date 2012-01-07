#include "Scene.hpp"

Scene::Scene()
{
  
}

Scene::~Scene()
{
  entities.clear();
}

void Scene::update(float dt)
{
  std::vector<Entity*>::iterator it = entities.begin();
  while(it != entities.end())
  {
    (*it)->update(dt);
    it++;
  }
}

void Scene::render()
{
  std::vector<Entity*>::iterator it = entities.begin();
  while(it != entities.end())
  {
    (*it)->render();
    it++;
  }
}

void Scene::addEntity(Entity *entity)
{
  entities.push_back(entity);
}

Entity* Scene::findEntity(int type)
{
  std::vector<Entity*>::iterator it = entities.begin();
  while(it != entities.end())
  {
    if((*it)->getType() == type)
      return *it;

    it++;
  }
  return 0;
}

std::vector<Entity*> Scene::findAllEntities(int type)
{
  std::vector<Entity*> result;
  std::vector<Entity*>::iterator it = entities.begin();
  while(it != entities.end())
  {
    if((*it)->getType() == type)
      result.push_back(*it);

    it++;
  }
  return result;
}
