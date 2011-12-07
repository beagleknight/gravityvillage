#include "TextureManager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
  int i;
  for(i = 0; i < N_TEXTURES; i++)
  {
    delete textures[i];
  }
}

void TextureManager::loadTexture(int id, const char *filename)
{
  Texture *texture;
  texture = new Texture();
  texture->load(filename,GL_RGBA);
  textures[id] = texture;
}

void TextureManager::setActive(int id)
{
  glBindTexture(GL_TEXTURE_2D,textures[id]->getId());
}
