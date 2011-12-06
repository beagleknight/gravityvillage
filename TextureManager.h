#ifndef CLASS_TEXTURE_MANAGER_H
#define CLASS_TEXTURE_MANAGER_H

#include "Globals.h"
#include "Texture.h"
#include "corona.h"

class TextureManager
{
  public:
    TextureManager();
    ~TextureManager();
    void loadTexture(const char*, const char*);
    void setActive(const char*);
  private:
    map<const char*, Texture*> textures;
};

#endif
