#ifndef CLASS_SPRITE_H
#define CLASS_SPRITE_H

#define COLLISION_X 0
#define COLLISION_Y 1

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
    float scale;
    float rotation;
    bool alive;
  public:
    Sprite();
    ~Sprite();
    virtual void init(int row, int col, const char *filename);
    virtual void render();
    virtual void update(float dt);
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
    void setScale(float _scale);
    void setRotation(float _rotation);
    bool collision(Sprite *sprite);
    void setAlive(bool _alive);
    bool isAlive();
    int getRow();
    int getCol();
    virtual void collisionMap(int type);
};

#endif
