#ifndef CLASS_ENEMY_H
#define CLASS_ENEMY_H

#include "Sprite.hpp"

#define ENEMY_GROUND 0
#define ENEMY_SKY 1

class Enemy : public Sprite
{
  public:
    Enemy();
    ~Enemy();
    void init(int row, int col, int texture_id, int _type);
    void update(float dt);
  private:
    int range;
    int init_row;
    int init_col;
    int type;
};

#endif
