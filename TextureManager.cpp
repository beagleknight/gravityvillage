#include "TextureManager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
  textures.clear();
}

void TextureManager::loadTexture(const char *id, const char *filename)
{
  Texture *texture;
  texture = new Texture();
  texture->load(filename,GL_RGBA);
  textures.insert(pair<const char*, Texture*>(id, texture));
}

void TextureManager::setActive(const char *id)
{
  if(textures[id] != NULL)
  {
    glBindTexture(GL_TEXTURE_2D,textures[id]->getId());
  }
}
