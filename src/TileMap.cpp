#include "TileMap.hpp"
#include <stdio.h>

TileMap::TileMap(int _rows, int _cols, int _tile_w, int _tile_h, const char *filename)
{
  rows = _rows;
  cols = _cols;
  tile_w = _tile_w;
  tile_h = _tile_h;

  tileset = new Texture();
  if(!tileset->load(filename))
  {
    printf("Error loading: texture '%s'\n", filename);
    exit(0);
  }

  map = new int*[rows];
  for(int i = 0; i < rows; i++)
    map[i] = new int[cols];

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(i < 2)
        map[i][j] = 1;
      else if(i < 3)
        map[i][j] = 0;
      else
        map[i][j] = 2;
    }
  }
}

TileMap::~TileMap()
{
  if(tileset != 0) delete tileset;
  if(map != 0)
  {
    for(int i = 0; i < rows; i++)
      delete[] map[i];
    delete[] map;
  }
}

void TileMap::draw()
{
  int x;
  int y;
  int current_frame;
  float xo,xf;

  glBindTexture(GL_TEXTURE_2D, tileset->getId());
  //TODO: wtf is wrong with you
  tileset->load("res/test.png");

  x = y = 0;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      current_frame = map[i][j];

      xo = current_frame*0.25f;
      xf = current_frame*0.25f + 0.25f;

      glPushMatrix();
      glTranslatef(x, y, 0.0f);
      glEnable(GL_TEXTURE_2D);
      glBegin(GL_QUADS);
      glVertex2f(0.0f, 0.0f);
      glTexCoord2f(xo, 0.0f);
      glVertex2f(0.0f, tile_h);
      glTexCoord2f(xf, 0.0f);
      glVertex2f(tile_w, tile_h);
      glTexCoord2f(xf, 1.0f);
      glVertex2f(tile_w, 0.0f);
      glTexCoord2f(xo, 1.0f);
      glEnd();
      glDisable(GL_TEXTURE_2D);
      glPopMatrix();

      x += tile_w;
    }

    x = 0;
    y += tile_h;
  }
}
