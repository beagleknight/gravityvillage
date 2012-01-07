#include "TextureManager.hpp"
#include <stdio.h>

TextureManager::TextureManager()
{
  textures = std::vector<Texture*> (100);        
}

TextureManager::~TextureManager()
{
  textures.clear();
}

void TextureManager::loadTexture(int id, const char *filename)
{
  Texture *texture;
  texture = new Texture();
  if(!texture->load(filename))
  {
    printf("Error loading: texture '%s'\n", filename);
    exit(0);
  }
  textures[id] = texture;
}

Texture* TextureManager::getTexture(int id)
{
  return textures[id];
}
