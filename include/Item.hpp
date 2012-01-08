#ifndef CLASS_ITEM_H
#define CLASS_ITEM_H

#include "Sprite.hpp"

#define ITEM_APPLE 0
#define ITEM_ORANGE 1
#define ITEM_COIN 2

class Item : public Sprite
{
  public:
    Item();
    ~Item();
    void init(int _item_type, int row, int col, int texture_id);
    int getItemType();
  private:
    int item_type;
};

#endif
