#ifndef CLASS_SPRITE_H
#define CLASS_SPRITE_H

#include "Texture.hpp"

class Sprite
{
  private:
    Texture *texture;
    int x;
    int y;
    int w;
    int h;
    int current_frame;
    int total_frames;
    int cols;
  public:
    Sprite();
    ~Sprite();
    void init(int _x, int _y, const char *filename);
    void render();
    void setX(int _x);
    int getX();
    void setY(int _y);
    int getY();
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
};

#endif
