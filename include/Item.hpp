#ifndef CLASS_ITEM_H
#define CLASS_ITEM_H

#include "Sprite.hpp"

#define ITEM_APPLE 0
#define ITEM_ORANGE 1

class Item : public Sprite
{
  public:
    Item();
    ~Item();
    void init(int _item_type, int row, int col, const char* filename);
    int getItemType();
  private:
    int item_type;
};

#endif
