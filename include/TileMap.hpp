#ifndef CLASS_TILE_MAP_H
#define CLASS_TILE_MAP_H

#include "Texture.hpp"

class TileMap
{
  private:
    int rows;
    int cols;
    int tile_w;
    int tile_h;
    Texture *tileset;
    int **map;
  public:
    TileMap(int _rows, int _cols, int _tile_w, int _tile_h, const char *filename);
    ~TileMap();
    void draw();
};

#endif
