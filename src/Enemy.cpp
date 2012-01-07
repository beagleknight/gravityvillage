#include "Enemy.hpp"

Enemy::Enemy()
{
  range = 2;
}

Enemy::~Enemy()
{

}

void Enemy::init(int row, int col, const char* filename)
{
  Sprite::init(row, col, filename);
  init_row = row;
  init_col = col;
}

void Enemy::update(float dt)
{
  if((getVelX() < 0 && (getX() < init_col*32 - range*32)) || 
      (getVelX() > 0 && (getX() > init_col*32 + range*32)))
  {
    setVelX(-getVelX()); 
  }
  Sprite::update(dt);
}
