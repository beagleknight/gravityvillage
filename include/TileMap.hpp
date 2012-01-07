#ifndef CLASS_TILE_MAP_H
#define CLASS_TILE_MAP_H

#include "Entity.hpp"
#include "Sprite.hpp"

class TileMap : public Entity
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
        int texture_id);
    void update(float dt);
    void render();
    void setCoordX(float _coord_x);
    float getCoordX();
    void setCoordY(float _coord_y);
    float getCoordY();
    int getTileType(int i, int j);
};

#endif
