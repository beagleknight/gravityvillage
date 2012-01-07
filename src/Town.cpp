#include "Town.hpp"
#include "TextureManager.hpp"

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

void Town::init(int row, int col, int texture_id)
{
  Sprite::init(row, col, texture_id);
  bubble = new Sprite();
  bubble->init(row+2, col+3, TEXTURE_BUBBLE);
  item = new Item();
  item->init(ITEM_APPLE, row+2, col+3, TEXTURE_ITEM_0);
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
