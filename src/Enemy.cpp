#include "Enemy.hpp"

Enemy::Enemy()
{
  setType(ENTITY_ENEMY);
}

Enemy::~Enemy()
{

}

void Enemy::init(int row, int col, int texture_id, int _type)
{
  Sprite::init(row, col, texture_id);
  init_row = row;
  init_col = col;
  type = _type;

  switch(type)
  {
    case ENEMY_GROUND:
      range = 2;
      break;
    case ENEMY_SKY:
      range = 4;
      break;
  }
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
