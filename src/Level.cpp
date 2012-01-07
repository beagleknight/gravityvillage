#include "Level.hpp"
#include "tinyxml.h"
#include "Game.hpp"
#include <stdio.h>

Level::Level(const char* _filename)
{
  filename = (char *) _filename;
}

Level::~Level()
{

}

void Level::init()
{
  clean();

  TiXmlNode* xLevel;   
  TiXmlDocument doc(filename);
  
  if(!doc.LoadFile())
  {
    printf("Error en cargar fichero %s\n", filename);
    exit(0);
  }
  else 
  {
    xLevel = doc.FirstChild("level");
  }

  TiXmlElement* xMap = xLevel->FirstChildElement("map");
  createTileMap(xMap);

  TiXmlElement* xPlayer = xLevel->FirstChildElement("player");
  createPlayer(xPlayer);

  TiXmlElement* xTowns = xLevel->FirstChildElement("towns");
  if(xTowns != 0)
  {
    for(TiXmlElement* xTown = xTowns->FirstChildElement("town"); xTown != 0; 
        xTown = xTown->NextSiblingElement("town"))
    {
      createTown(xTown);
    }
  }

  TiXmlElement* xItems = xLevel->FirstChildElement("items");
  if(xItems != 0)
  {
    for(TiXmlElement* xItem = xItems->FirstChildElement("item"); xItem != 0; 
        xItem = xItem->NextSiblingElement("item"))
    {
      createItem(xItem);
    }
  }

  TiXmlElement* xEnemies = xLevel->FirstChildElement("enemies");
  if(xEnemies != 0)
  {
    for(TiXmlElement* xEnemy = xEnemies->FirstChildElement("enemy"); xEnemy != 0; 
        xEnemy = xEnemy->NextSiblingElement("enemy"))
    {
      createEnemy(xEnemy);
    }
  }
}

void Level::createTileMap(TiXmlElement* xMap)
{
  int rows, cols, tilew, tileh;
  TileMap *map;

  if(xMap != 0)
  {
    sscanf(xMap->Attribute("rows"), "%d", &rows);
    sscanf(xMap->Attribute("cols"), "%d", &cols);
    sscanf(xMap->Attribute("tilew"), "%d", &tilew);
    sscanf(xMap->Attribute("tileh"), "%d", &tileh);
    
    map = new TileMap();
    map->init(rows, cols, 8, 10, tilew, tileh, TEXTURE_MAP, xMap->Attribute("src"));
    addEntity(map);
  }
}

void Level::createPlayer(TiXmlElement* xPlayer)
{
  int row, col, cols, frames, width, height;
  float animationtime;
  Player *player;

  if(xPlayer != 0)
  {
    sscanf(xPlayer->Attribute("row"), "%d", &row);
    sscanf(xPlayer->Attribute("col"), "%d", &col);

    TiXmlElement* xSprite = xPlayer->FirstChildElement("sprite");
    sscanf(xSprite->Attribute("cols"), "%d", &cols);
    sscanf(xSprite->Attribute("frames"), "%d", &frames);
    sscanf(xSprite->Attribute("width"), "%d", &width);
    sscanf(xSprite->Attribute("height"), "%d", &height);
    sscanf(xSprite->Attribute("animationtime"), "%f", &animationtime);

    player = new Player();
    player->init(row, col, TEXTURE_PLAYER);
    player->setCols(cols);
    player->setTotalFrames(frames);
    player->setWidth(width);
    player->setHeight(height);
    player->setAnimationTime(animationtime);
    addEntity(player);
  }
}

void Level::createItem(TiXmlElement* xItem)
{
  Item* item;
  int row, col, type;

  if(xItem != 0)
  {
    sscanf(xItem->Attribute("row"), "%d", &row);
    sscanf(xItem->Attribute("col"), "%d", &col);
    sscanf(xItem->Attribute("type"), "%d", &type); 

    item = new Item();
    item->init(type, row, col, TEXTURE_ITEM_0);
    addEntity(item);
  }
}

void Level::createTown(TiXmlElement* xTown)
{
  int row, col;
  Town* town;

  if(xTown != 0)
  {
    sscanf(xTown->Attribute("row"), "%d", &row);
    sscanf(xTown->Attribute("col"), "%d", &col);

    town = new Town();
    town->init(row, col, TEXTURE_TOWN);
    addEntity(town);
  }
}

void Level::createEnemy(TiXmlElement* xEnemy)
{
  int row, col, velx, cols, frames, width, height;
  float animationtime;
  Enemy *enemy;

  if(xEnemy != 0)
  {
    sscanf(xEnemy->Attribute("row"), "%d", &row);
    sscanf(xEnemy->Attribute("col"), "%d", &col);
    sscanf(xEnemy->Attribute("velx"), "%d", &velx);

    TiXmlElement* xSprite = xEnemy->FirstChildElement("sprite");
    sscanf(xSprite->Attribute("cols"), "%d", &cols);
    sscanf(xSprite->Attribute("frames"), "%d", &frames);
    sscanf(xSprite->Attribute("width"), "%d", &width);
    sscanf(xSprite->Attribute("height"), "%d", &height);
    sscanf(xSprite->Attribute("animationtime"), "%f", &animationtime);

    enemy = new Enemy();
    enemy->init(row, col, TEXTURE_ENEMY_0);
    enemy->setCols(cols);
    enemy->setTotalFrames(frames);
    enemy->setWidth(width);
    enemy->setHeight(height);
    enemy->setAnimationTime(animationtime);
    enemy->setVelX(velx);
    addEntity(enemy);
  }
}
