#include "Player.hpp"

Player::Player()
{
  texture = 0;
}

Player::~Player()
{
  if(texture != 0) delete texture;
}

void Player::init(int _x, int _y, const char* filename)
{
  x = _x;
  y = _y;
  texture = new Texture();
  texture->load(filename);
}

void Player::render()
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture->getId());

  glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 0.0f);
      glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, texture->getHeight());
      glTexCoord2f(1.0f, 0.0f); glVertex2f(texture->getWidth(), texture->getHeight());
      glTexCoord2f(1.0f, 1.0f); glVertex2f(texture->getWidth(), 0.0f);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}
