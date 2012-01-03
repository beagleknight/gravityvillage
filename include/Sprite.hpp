#ifndef CLASS_SPRITE_H
#define CLASS_SPRITE_H

#include "Texture.hpp"

class Sprite
{
  private:
    Texture *texture;
    float vx;
    float vy;
    float x;
    float y;
    int w;
    int h;
    int current_frame;
    int total_frames;
    int cols;
    float animation_counter;
    float animation_time;
  public:
    Sprite();
    ~Sprite();
    void init(float _x, float _y, const char *filename);
    void render();
    void update(float dt);
    void setX(float _x);
    float getX();
    void setY(float _y);
    float getY();
    void setVelX(float _vx);
    float getVelX();
    void setVelY(float _vy);
    float getVelY();
    void setWidth(int _w);
    int getWidth();
    void setHeight(int _h);
    int getHeight();
    void setCurrentFrame(int _current_frame);
    int getCurrentFrame();
    void setTotalFrames(int _total_frames);
    int getTotalFrames();
    void setCols(int _cols);
    int getCols();
    void setAnimationTime(float _animation_time);
};

#endif
