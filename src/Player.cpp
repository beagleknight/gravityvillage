#include "Player.hpp"
#include "Game.hpp"
#include <stdio.h>
#include <math.h>

extern Game game;

Player::Player()
{
  move_velocity = 100;
  jumping = false;
}

Player::~Player()
{

}

void Player::update(float dt)
{
  if(isJumping())
  {
    setVelY(jump_velocity);
    jump_velocity -= 250*dt;
  }
  else
  {
    setVelY(-250);
  }

  if(collision(&game.item))
  {
    game.item.setAlive(false);
  }

  if(collision(&game.enemy))
  {
    exit(0);
  }

  Sprite::update(dt);
}

void Player::move_right()
{
  setVelX(move_velocity);
  setRotation(0);
  setAnimationTime(0.5f);
}

void Player::move_left()
{
  setVelX(-move_velocity);
  setRotation(-180);
  setAnimationTime(0.5f);
}

void Player::jump()
{
  if(!isJumping())
  {
    jumping = true;
    jump_velocity = 200;
  }
}

void Player::halt()
{
  setVelX(0);
  setAnimationTime(0);
}

bool Player::isJumping()
{
  return jumping;
}

void Player::collisionMap(int type)
{
  if(type == COLLISION_X)
    halt();
  else if(type == COLLISION_Y)
    jumping = false;
}
