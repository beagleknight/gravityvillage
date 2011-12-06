#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Globals.h"
#include "TextureManager.h"

class Scene
{
  public:
    Scene();
    ~Scene();
    void render();
    void update(float);
};

#endif
