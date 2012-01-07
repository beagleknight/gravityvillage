#include "Town.hpp"

Town::Town()
{
  bubble = 0;
  item = 0;
}

Town::~Town()
{
  if(bubble != 0) delete bubble;
  if(item != 0) delete item;
}

void Town::init(int row, int col, const char* filename)
{
  Sprite::init(row, col, filename);
  bubble = new Sprite();
  bubble->init(row+2, col+3, "res/bubble.png");
  item = new Item();
  item->init(ITEM_APPLE, row+2, col+3, "res/apple.png");
  item->setX(item->getX()+15);
  item->setY(item->getY()+20);
}

void Town::render()
{
  Sprite::render();
  bubble->render();
  item->render();
}

int Town::itemRequested()
{
  return item->getItemType();
}
