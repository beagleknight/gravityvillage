#include "Town.hpp"
#include "Game.hpp"

extern Game game;

Town::Town()
{
  bubble = 0;
  setType(ENTITY_TOWN);
}

Town::~Town()
{
  if(bubble != 0) delete bubble;
  items.clear();
}

void Town::init(int row, int col, int texture_id, int _time)
{
  Sprite::init(row, col, texture_id);
  bubble = new Sprite();
  bubble->init(row+2, col+3, TEXTURE_BUBBLE);
  time = _time;
  counter = 0;
}

void Town::addItem(Item* item)
{
  items.push_back(item);
  if(items.size() == 1)
    it = items.begin();
}

bool Town::nextItem()
{
  it++;
  return it != items.end();
}

void Town::render()
{
  Sprite::render();
  bubble->render();
  (*it)->render();
}

void Town::update(float dt)
{
  string text;
  char time_remaining[10];

  counter += dt;

  TextLabel *label = (TextLabel*) game.getSceneManager()->getActive()->findEntity(string("time"));
  if(label != 0)
  {
    sprintf(time_remaining, "%d", (int) getTimeRemaining());
    text = "Time: ";
    text += time_remaining;
    label->setText(text); 
  }

  if(counter >= time)
    game.setGameOver(true);
}

int Town::itemRequested()
{
  return (*it)->getItemType();
}

float Town::getTimeRemaining()
{
  return (float) time - counter;
}
