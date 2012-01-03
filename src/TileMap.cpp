#include "TileMap.hpp"

TileMap::TileMap()
{
  sprite = 0;
  map = 0;
}

TileMap::~TileMap()
{
  if(sprite != 0) delete sprite;
  if(map != 0)
  {
    for(int i = 0; i < rows; i++)
      delete[] map[i];
    delete[] map;
  }
}

void TileMap::init(int _rows, int _cols, int _scene_w, int _scene_h, int _tile_w, int _tile_h, 
    const char *filename)
{
  rows = _rows;
  cols = _cols;
  tile_w = _tile_w;
  tile_h = _tile_h;
  scene_w = _scene_w;
  scene_h = _scene_h;

  coord_x = 0;
  coord_y = 0;

  sprite = new Sprite();
  sprite->init(0, 0, filename);
  sprite->setWidth(tile_w);
  sprite->setHeight(tile_h);
  sprite->setTotalFrames(5);
  sprite->setCols(4);

  map = new int*[rows];
  for(int i = 0; i < rows; i++)
    map[i] = new int[cols];

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(i < 2)
      {
        if( j > 5)
        {
          map[i][j] = 1;
        }
        else
        {
          map[i][j] = 4;
        }
      }
      else if(i < 3)
        map[i][j] = 0;
      else
        map[i][j] = 2;
    }
  }
}

void TileMap::render()
{
  int x, y;
  int x0, xf;
  int y0, yf;

  int offset_x = (int) coord_x % tile_w;
  int offset_y = (int) coord_y % tile_h;

  x = -offset_x; 
  y = -offset_y;

  x0 = (int) coord_x / tile_w;
  xf = x0 + scene_w - 1;
  if(offset_x != 0) xf++;

  y0 = (int) coord_y / tile_h;
  yf = y0 + scene_h - 1;
  if(offset_y != 0) yf++;

  for(int i = x0; i <= xf; i++)
  {
    for(int j = y0; j <= yf; j++)
    {
      sprite->setCurrentFrame(map[i][j]);
      sprite->setX(x);
      sprite->setY(y);
      sprite->render();

      x += tile_w;
    }

    x = -offset_x;
    y += tile_h;
  }
}

void TileMap::setCoordX(float _coord_x)
{
  coord_x = _coord_x;
}

float TileMap::getCoordX()
{
  return coord_x;
}

void TileMap::setCoordY(float _coord_y)
{
  coord_y = _coord_y;
}

float TileMap::getCoordY()
{
  return coord_y;
}
