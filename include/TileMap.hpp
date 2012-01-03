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
    int scene_w;
    int scene_h;
    float coord_x;
    float coord_y;
    Sprite *sprite;
    int **map;
  public:
    TileMap();
    ~TileMap();
    void init(int _rows, int _cols, int _scene_w, int _scene_h, int _tile_w, int _tile_h, 
        const char *filename);
    void render();
    void setCoordX(float _coord_x);
    float getCoordX();
    void setCoordY(float _coord_y);
    float getCoordY();
};

#endif
