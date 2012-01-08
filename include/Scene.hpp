#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Entity.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Scene
{
  public:
    Scene();
    ~Scene();
    void clean();
    void update(float dt);
    void render(); 
    void renderGUI();
    void addEntity(Entity *entity);
    void addGUIElement(Entity *entity);
    Entity* findEntity(int type);
    Entity* findEntity(string id);
    vector<Entity*> findAllEntities(int type);
  private:
    vector<Entity*> entities;
    vector<Entity*> gui_elements;
};

#endif
