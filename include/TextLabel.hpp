#ifndef CLASS_TEXT_LABEL_H
#define CLASS_TEXT_LABEL_H

#include <iostream>
#include <string>
#include "Entity.hpp"
using namespace std;

class TextLabel : public Entity
{
  public:
    TextLabel(int _x, int _y, string _text);
    ~TextLabel();
    void render();
    void update(float dt);
    int x;
    int y;
    void setText(string _text);
  private:
    string text;
};

#endif
