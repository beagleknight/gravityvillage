#include "TextLabel.hpp"
#include <GL/glut.h>
#include <string.h>

TextLabel::TextLabel(int _x, int _y, string _text)
{
  x = _x;
  y = _y;
  text = _text;
}

TextLabel::~TextLabel()
{

}

void TextLabel::render()
{
  int len, i;
  void *font = GLUT_BITMAP_TIMES_ROMAN_24;

  glRasterPos2f(x, y);
  len = (int) strlen(text.c_str());
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, text.c_str()[i]);
  }
}

void TextLabel::update(float dt)
{

}

void TextLabel::setText(string _text)
{
  text = _text;
}
