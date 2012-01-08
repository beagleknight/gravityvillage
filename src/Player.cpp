#include "Player.hpp"
#include "Game.hpp"
#include <stdio.h>
#include <math.h>

extern Game game;

Player::Player()
{
  move_velocity = 200;
  jumping = false;
  setType(ENTITY_PLAYER);
  backpack = 0;
  lives = 2;
  score = 0;
}

Player::~Player()
{

}

void Player::update(float dt)
{
  char str[10];
  string text;
  std::vector<Entity*> entities;
  std::vector<Entity*>::iterator it; 

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
    jump_velocity -= 500*dt;
  }
  else
  {
    setVelY(-250);
  }

  Scene *scene;
  scene = game.getSceneManager()->getActive();

  // check collisions against items
  entities = scene->findAllEntities(ENTITY_ITEM);
  it = entities.begin();
  while(it != entities.end())
  {
    if(collision((Item*)(*it)))
    {
      switch(((Item*)(*it))->getItemType())
      {
        case ITEM_APPLE:
        case ITEM_ORANGE:
          pickItem((Item*)(*it));
          game.getSoundManager()->playFX(SOUND_PICK_QUEST);
          break;
        case ITEM_COIN:
          ((Item*)(*it))->setAlive(false);
          score++;
          game.getSoundManager()->playFX(SOUND_PICK_ITEM);
          break;
      }

    }
    it++;
  }

  // check collision against town
  Town *town = (Town*) scene->findEntity(ENTITY_TOWN);
  if(town != 0 && collision(town))
  {
    if(backpack != 0 && (backpack->getItemType() == town->itemRequested()))
      game.setVictory(true);
  }

  // check collision against enemies
  entities = scene->findAllEntities(ENTITY_ENEMY);
  it = entities.begin();
  while(it != entities.end())
  {
    if(collision((Enemy*) (*it)))
      game.setGameOver(true);
    it++;
  }

  // check if we died on a pit
  if(getY() < 0)
    game.setGameOver(true);

  TextLabel *label;
  // update lives counter
  label = (TextLabel*) scene->findEntity("lives");
  if(label != 0)
  {
    sprintf(str, "%d", lives);
    text = "Lives: ";
    text += str;
    label->setText(text); 
  }
  // update score counter
  label = (TextLabel*) scene->findEntity("score");
  if(label != 0)
  {
    sprintf(str, "%d", score);
    text = "Score: ";
    text += str;
    label->setText(text); 
  }

  Sprite::update(dt);
}

void Player::move_right()
{
  setVelX(move_velocity);
  setRotation(0);
  setAnimationTime(0.25f);
}

void Player::move_left()
{
  setVelX(-move_velocity);
  setRotation(-180);
  setAnimationTime(0.25f);
}

void Player::jump()
{
  if(!isJumping())
  {
    jumping = true;
    jump_velocity = 300;
    game.getSoundManager()->playFX(SOUND_JUMP);
  }
}

void Player::halt()
{
  setVelX(0);
  setAnimationTime(0);
  setCurrentFrame(3);
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
  item->setAlive(false);
  backpack = item;
}

void Player::releaseItem()
{
  backpack = 0;
}

void Player::setLives(int _lives)
{
  lives = _lives;
}
