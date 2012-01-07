#ifndef CLASS_ENEMY_H
#define CLASS_ENEMY_H

#include "Sprite.hpp"

class Enemy : public Sprite
{
  public:
    Enemy();
    ~Enemy();
    void init(int row, int col, const char* filename);
    void update(float dt);
  private:
    int range;
    int init_row;
    int init_col;
};

#endif
