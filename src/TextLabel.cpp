#include "TextLabel.hpp"
#include <GL/glut.h>
#include <string.h>

TextLabel::TextLabel(int _x, int _y, const char* _string)
{
  string = new char[strlen(_string)+1];
  strcpy(string, _string); 
  x = _x;
  y = _y;
}

TextLabel::~TextLabel()
{
  delete[] string;
}

void TextLabel::render()
{
  int len, i;
  void *font = GLUT_BITMAP_TIMES_ROMAN_24;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void TextLabel::update(float dt)
{

}
