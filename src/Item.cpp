#include "Item.hpp"

Item::Item()
{

}

Item::~Item()
{

}

void Item::init(int _item_type, int row, int col, const char* filename)
{
  Sprite::init(row, col, filename);
  item_type = _item_type;
}

int Item::getItemType()
{
  return item_type;
}
