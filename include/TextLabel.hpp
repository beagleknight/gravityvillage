#ifndef CLASS_TEXT_LABEL_H
#define CLASS_TEXT_LABEL_H

#include "Entity.hpp"

class TextLabel : public Entity
{
  public:
    TextLabel(int _x, int _y, const char* _string);
    ~TextLabel();
    void render();
    void update(float dt);
    int x;
    int y;
  private:
    char *string;
};

#endif
