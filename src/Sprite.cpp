#include "Sprite.hpp"
#include <stdio.h>

Sprite::Sprite()
{
  x = y = vx = vy = 0;
  texture = 0;
  current_frame = 0;
  total_frames = 1;
  cols = 1;
  animation_counter = 0;
  animation_time = 0;
  scale = 1;
  alive = true;
}

Sprite::~Sprite()
{
  if(texture != 0) delete texture;
}

void Sprite::init(float _x, float _y, const char *filename)
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
  if(alive)
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
      glScalef(scale, scale, 1);
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
}

void Sprite::update(float dt)
{
  x += vx*dt;
  y += vy*dt;
   
  if(animation_time > 0)
  {
    animation_counter += dt;
    if(animation_counter > animation_time)
    {
      current_frame = (current_frame + 1) % total_frames;
      animation_counter = 0;
    }
  }
}

void Sprite::setX(float _x)
{
  x = _x;
}

float Sprite::getX()
{
  return x;
}

void Sprite::setY(float _y)
{
  y = _y;
}

float Sprite::getY()
{
  return y;
}

void Sprite::setVelX(float _vx)
{
  vx = _vx;
}

float Sprite::getVelX()
{
  return vx;
}

void Sprite::setVelY(float _vy)
{
  vy = _vy;
}

float Sprite::getVelY()
{
  return vy;
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

void Sprite::setAnimationTime(float _animation_time)
{
  animation_time = _animation_time;
}

void Sprite::setScale(float _scale)
{
  scale = _scale;
}

bool Sprite::collision(Sprite *sprite)
{
  int x1_1 = x;
  int y1_1 = y;
  int x2_1 = x + w;
  int y2_1 = y + h;    
  int x1_2 = sprite->getX();
  int y1_2 = sprite->getY();
  int x2_2 = sprite->getX() + sprite->getWidth();
  int y2_2 = sprite->getY() + sprite->getHeight();

  return (x1_1 < x2_2) && (x2_1 > x1_2) && (y1_1 < y2_2) && (y2_1 > y1_2);
}

void Sprite::setAlive(bool _alive)
{
  alive = _alive;
}

bool Sprite::isAlive()
{
  return alive;
}
