#ifndef CLASS_TOWN_H
#define CLASS_TOWN_H

#include <vector>
#include "Sprite.hpp"
#include "Item.hpp"

class Town : public Sprite
{
  public:
    Town();
    ~Town();
    void init(int row, int col, int texture_id, int _time);
    void render();
    void update(float dt);
    void addItem(Item *item);
    bool nextItem();
    int itemRequested();
    float getTimeRemaining();
  private:
    Sprite *bubble;
    std::vector<Item*> items;
    std::vector<Item*>::iterator it;
    int time;
    float counter;
};

#endif
