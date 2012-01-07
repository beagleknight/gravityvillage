#ifndef CLASS_TOWN_H
#define CLASS_TOWN_H

#include "Sprite.hpp"
#include "Item.hpp"

class Town : public Sprite
{
  public:
    Town();
    ~Town();
    void init(int row, int col, const char* filename);
    void render();
    int itemRequested();
  private:
    Sprite *bubble;
    Item *item;
};

#endif
