#ifndef CLASS_TEXTURE_MANAGER_H
#define CLASS_TEXTURE_MANAGER_H

#include "Texture.hpp"
#include <vector>

#define TEXTURE_MAP 0
#define TEXTURE_PLAYER 1
#define TEXTURE_ITEM_0 2
#define TEXTURE_ENEMY_0 3
#define TEXTURE_TOWN 4
#define TEXTURE_BUBBLE 5

class TextureManager
{
  public:
    TextureManager();
    ~TextureManager();
    void loadTexture(int id, const char *filename);
    Texture* getTexture(int id);
  private:
    std::vector<Texture*> textures;
};

#endif
