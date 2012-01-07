#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.hpp"
#include <vector>

#define SCENE_GAME 0
#define SCENE_START 1
#define SCENE_END 2

class SceneManager
{
  public:
    SceneManager();
    ~SceneManager();
    void addScene(int id, Scene *scene);
    Scene* getActive();
    int getActiveId();
    void setActive(int id);
    void update(float dt);
    void render();
    void renderGUI();
  private:
    int active;
    std::vector<Scene*> scenes;
};

#endif
