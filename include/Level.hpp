#ifndef CLASS_LEVEL_H
#define CLASS_LEVEL_H

#include "Scene.hpp"
#include "tinyxml.h"

class Level : public Scene
{
  public:
    Level(const char* _filename);
    ~Level();
    void init();
  private:
    char* filename;
    void createTileMap(TiXmlElement* xMap);
    void createPlayer(TiXmlElement* xPlayer);
    void createItem(TiXmlElement* xItem);
    void createTown(TiXmlElement* xTown);
    void createEnemy(TiXmlElement* xEnemy);
};

#endif
