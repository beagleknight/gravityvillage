#include "Item.hpp"

Item::Item()
{

}

Item::~Item()
{

}

void Item::init(int _item_type, int row, int col, int texture_id)
{
  Sprite::init(row, col, texture_id);
  item_type = _item_type;
}

int Item::getItemType()
{
  return item_type;
}
