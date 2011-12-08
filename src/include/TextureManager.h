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
    void loadTexture(int, const char*);
    void setActive(int);
    // Constants
    static const int N_TEXTURES = 2; 
    static const int TEX_PLAYER= 0; 
    static const int TEX_MAP = 1; 
  private:
    Texture* textures[TextureManager::N_TEXTURES];
};

#endif
