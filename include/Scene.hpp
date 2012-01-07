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
    void renderGUI();
    void addEntity(Entity *entity);
    void addGUIElement(Entity *entity);
    Entity* findEntity(int type);
    std::vector<Entity*> findAllEntities(int type);
  private:
    std::vector<Entity*> entities;
    std::vector<Entity*> gui_elements;
};

#endif
