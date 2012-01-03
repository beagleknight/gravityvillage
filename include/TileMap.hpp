#ifndef CLASS_TILE_MAP_H
#define CLASS_TILE_MAP_H

#include "Sprite.hpp"

class TileMap
{
  private:
    int rows;
    int cols;
    int tile_w;
    int tile_h;
    Sprite *sprite;
    int **map;
  public:
    TileMap();
    ~TileMap();
    void init(int _rows, int _cols, int _tile_w, int _tile_h, const char *filename);
    void render();
};

#endif
