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
  if(game.map.getTileType(getRow(), getCol()) == 0)
  {
    setVelY(0);
    setY(getY()+1);
    jumping = false;
  }
  else
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
  }
  
  Sprite::update(dt);
}

void Player::move_right()
{
  setVelX(move_velocity);
  setRotation(0);
}

void Player::move_left()
{
  setVelX(-move_velocity);
  setRotation(-180);
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
}

bool Player::isJumping()
{
  return jumping;
}

int Player::getRow()
{
  return (int) getY() / 32;
}

int Player::getCol()
{
  return (int) getX() / 32;
}
