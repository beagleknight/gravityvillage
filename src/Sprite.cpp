#include "Sprite.hpp"
#include <stdio.h>

Sprite::Sprite()
{
  texture = 0;
  current_frame = 0;
  total_frames = 1;
  cols = 1;
}

Sprite::~Sprite()
{
  if(texture != 0) delete texture;
}

void Sprite::init(int _x, int _y, const char *filename)
{
  x = _x;
  y = _y;

  texture = new Texture();
  if(!texture->load(filename))
  {
    printf("Error loading: texture '%s'\n", filename);
    exit(0);
  }
  w = texture->getWidth();
  h = texture->getHeight();
}

void Sprite::render()
{
  float frame_w = (float) w / texture->getWidth();
  float frame_h = (float) h / texture->getHeight();
  int tx = current_frame % cols;
  int ty = current_frame / cols;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture->getId());
  glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
      glTexCoord2f(tx * frame_w, ty * frame_h + frame_h);
      glVertex2f(0.0f, 0.0f);
      glTexCoord2f(tx * frame_w, ty * frame_h);
      glVertex2f(0.0f, h);
      glTexCoord2f(tx * frame_w + frame_w, ty * frame_h);
      glVertex2f(w, h);
      glTexCoord2f(tx * frame_w + frame_w, ty * frame_h + frame_h);
      glVertex2f(w, 0.0f);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void Sprite::setX(int _x)
{
  x = _x;
}

int Sprite::getX()
{
  return x;
}

void Sprite::setY(int _y)
{
  y = _y;
}

int Sprite::getY()
{
  return y;
}

void Sprite::setWidth(int _w)
{
  w = _w;
}

int Sprite::getWidth()
{
  return w;
}

void Sprite::setHeight(int _h)
{
  h = _h;
}

int Sprite::getHeight()
{
  return h;
}

void Sprite::setCurrentFrame(int _current_frame)
{
  current_frame = _current_frame;
}

int Sprite::getCurrentFrame()
{
  return current_frame;
}

void Sprite::setTotalFrames(int _total_frames)
{
  total_frames = _total_frames;
}

int Sprite::getTotalFrames()
{
  return total_frames;
}

void Sprite::setCols(int _cols)
{
  cols = _cols;
}

int Sprite::getCols()
{
  return cols;
}
