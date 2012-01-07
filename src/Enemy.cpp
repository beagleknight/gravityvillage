#include "Enemy.hpp"

Enemy::Enemy()
{
  range = 2;
  setType(ENTITY_ENEMY);
}

Enemy::~Enemy()
{

}

void Enemy::init(int row, int col, int texture_id)
{
  Sprite::init(row, col, texture_id);
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
