#include "TileMap.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

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
    int texture_id)
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
  sprite->init(0, 0, texture_id);
  sprite->setWidth(tile_w);
  sprite->setHeight(tile_h);
  sprite->setTotalFrames(5);
  sprite->setCols(4);

  map = new int*[rows];
  for(int i = 0; i < rows; i++)
    map[i] = new int[cols];

  
  // reading level hard coded
  int i, j;
  string line;
  char * pch;

  i = j = 0;
  ifstream myfile ("res/level0.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      pch = strtok ((char *)line.c_str(),",");
      while (pch != NULL)
      {
        map[i][j] = atoi(pch);
        j++;
        pch = strtok (NULL, ",");
      }
      j = 0;
      i++;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}

void TileMap::render()
{
  int x, y;

  x = y = 0;
  for(int i = rows-1; i >= 0; i--)
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

int TileMap::getTileType(int i, int j)
{
  return map[rows-1-i][j];
}
