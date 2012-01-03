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

void TileMap::init(int _rows, int _cols, int _tile_w, int _tile_h, const char *filename)
{
  rows = _rows;
  cols = _cols;
  tile_w = _tile_w;
  tile_h = _tile_h;

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
        map[i][j] = 1;
      else if(i < 3)
        map[i][j] = 0;
      else
        map[i][j] = 2;
    }
  }
}

void TileMap::render()
{
  int x;
  int y;

  x = y = 0;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      sprite->setCurrentFrame(map[i][j]);
      sprite->setX(x);
      sprite->setY(y);
      sprite->render();

      x += tile_w;
    }

    x = 0;
    y += tile_h;
  }
}
