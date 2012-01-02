#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include "Texture.hpp"

class Player
{
  private:
    Texture *texture;
    int x;
    int y;
  public:
    Player();
    ~Player();
    void init(int _x, int _y, const char* filename);
    void render();
};

#endif
