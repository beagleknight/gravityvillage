#ifndef CLASS_SCENE_MANAGER_H
#define CLASS_SCENE_MANAGER_H

#include "Globals.h"
#include "Scene.h"

class SceneManager
{
  public:
    SceneManager();
    ~SceneManager();
    void render();
    void update(float);
    void setActive(const char*);
    void addScene(const char*, Scene);
  private:
    map<const char*, Scene*> scenes;
    const char *active;
};

#endif
