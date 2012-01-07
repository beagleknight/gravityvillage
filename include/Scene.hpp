#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Entity.hpp"
#include <vector>

class Scene
{
  public:
    Scene();
    ~Scene();
    void update(float dt);
    void render(); 
    void addEntity(Entity *entity);
    Entity* findEntity(int type);
    std::vector<Entity*> findAllEntities(int type);
  private:
    std::vector<Entity*> entities;
};

#endif
