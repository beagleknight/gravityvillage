#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include "Sprite.hpp"

class Player : public Sprite
{
  public:
    Player();
    ~Player();
    void update(float dt);
    void move_right();
    void move_left();
    void jump();
    void halt();
    bool isJumping();
    int getRow();
    int getCol();
  private:
    int move_velocity;
    float jump_velocity;
    bool jumping;
};

#endif
