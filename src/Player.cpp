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
  // control logic
  if(game.keyPressed(GLUT_KEY_LEFT))
    move_left();
  else if(game.keyPressed(GLUT_KEY_RIGHT))
    move_right();
  else
    halt();
  
  if(game.keyPressed(32)) // space to jump
    jump();

  // jumping logic
  if(isJumping())
  {
    setVelY(jump_velocity);
    jump_velocity -= 300*dt;
  }
  else
  {
    setVelY(-250);
  }

  // check collisions against items
  if(collision(&game.item))
  {
    game.item.setAlive(false);
    pickItem(&game.item);
  }

  // check collision against town
  if(collision(&game.town))
  {
    if(backpack != 0 && (backpack->getItemType() == game.town.itemRequested()))
      exit(0);
  }

  // check collision agains enemies
  for(int i = 0; i < game.enemies.size(); i++)
  {
    if(collision(game.enemies[i]))
    {
      exit(0);
    }
  }

  if(getY() < 0)
    exit(0);

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

void Player::pickItem(Item *item)
{
  backpack = item;
}

void Player::releaseItem()
{
  backpack = 0;
}
