#include "Level.hpp"
#include "tinyxml.h"
#include "Game.hpp"
#include <stdio.h>

Level::Level(const char* _filename)
{
  filename = (char *) _filename;
  init();
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

  TiXmlElement* xTowns = xLevel->FirstChildElement("towns");
  if(xTowns != 0)
  {
    for(TiXmlElement* xTown = xTowns->FirstChildElement("town"); xTown != 0; 
        xTown = xTown->NextSiblingElement("town"))
    {
      createTown(xTown);
    }
  }

  TiXmlElement* xPlayer = xLevel->FirstChildElement("player");
  createPlayer(xPlayer);

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

  TiXmlElement* xGUI = xLevel->FirstChildElement("gui");
  if(xGUI != 0)
  {
    for(TiXmlElement* xTextLabel = xGUI->FirstChildElement("textlabel"); xTextLabel != 0; 
        xTextLabel = xTextLabel->NextSiblingElement("textlabel"))
    {
      createTextLabel(xTextLabel);
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
  int texture;

  if(xItem != 0)
  {
    sscanf(xItem->Attribute("row"), "%d", &row);
    sscanf(xItem->Attribute("col"), "%d", &col);
    sscanf(xItem->Attribute("type"), "%d", &type); 

    item = new Item();
    switch(type)
    {
      case ITEM_APPLE:
        texture = TEXTURE_ITEM_0;
        break;
      case ITEM_ORANGE:
        texture = TEXTURE_ORANGE;
        break;
      case ITEM_COIN:
        texture = TEXTURE_COIN;
        break;
    }
    item->init(type, row, col, texture);
    addEntity(item);
  }
}

void Level::createTown(TiXmlElement* xTown)
{
  int row, col, time, type;
  int texture;
  Town* town;
  Item *item;

  if(xTown != 0)
  {
    sscanf(xTown->Attribute("row"), "%d", &row);
    sscanf(xTown->Attribute("col"), "%d", &col);
    sscanf(xTown->Attribute("time"), "%d", &time);

    town = new Town();
    town->init(row, col, TEXTURE_TOWN, time);

    TiXmlElement* xItems = xTown->FirstChildElement("items");
    for(TiXmlElement* xItem = xItems->FirstChildElement("item"); xItem != 0; 
      xItem = xItem->NextSiblingElement("item"))
    {
      item = new Item();
      sscanf(xItem->Attribute("type"), "%d", &type); 
      switch(type)
      {
        case ITEM_APPLE:
          texture = TEXTURE_ITEM_0;
          break;
        case ITEM_ORANGE:
          texture = TEXTURE_ORANGE;
          break;
        case ITEM_COIN:
          texture = TEXTURE_COIN;
          break;
      }
      item->init(type, row+2, col+3, texture);
      item->setX(item->getX()+15);
      item->setY(item->getY()+20);
      town->addItem(item);
    }
    addEntity(town);
  }
}

void Level::createEnemy(TiXmlElement* xEnemy)
{
  int row, col, velx, cols, frames, width, height, type;
  int texture;
  float animationtime;
  Enemy *enemy;

  if(xEnemy != 0)
  {
    sscanf(xEnemy->Attribute("row"), "%d", &row);
    sscanf(xEnemy->Attribute("col"), "%d", &col);
    sscanf(xEnemy->Attribute("velx"), "%d", &velx);
    sscanf(xEnemy->Attribute("type"), "%d", &type);

    switch(type)
    {
      case ENEMY_GROUND:
        texture = TEXTURE_ENEMY_0;
        break;
      case ENEMY_SKY:
        texture = TEXTURE_TURTLE;
        break;
    }

    TiXmlElement* xSprite = xEnemy->FirstChildElement("sprite");
    sscanf(xSprite->Attribute("cols"), "%d", &cols);
    sscanf(xSprite->Attribute("frames"), "%d", &frames);
    sscanf(xSprite->Attribute("width"), "%d", &width);
    sscanf(xSprite->Attribute("height"), "%d", &height);
    sscanf(xSprite->Attribute("animationtime"), "%f", &animationtime);

    enemy = new Enemy();
    enemy->init(row, col, texture, type);
    enemy->setCols(cols);
    enemy->setTotalFrames(frames);
    enemy->setWidth(width);
    enemy->setHeight(height);
    enemy->setAnimationTime(animationtime);
    enemy->setVelX(velx);
    addEntity(enemy);
  }
}

void Level::createTextLabel(TiXmlElement* xTextLabel)
{
  int x, y;
  TextLabel *textlabel;
  char id[256];
  
  if(xTextLabel != 0)
  {
    sscanf(xTextLabel->Attribute("x"), "%d", &x);   
    sscanf(xTextLabel->Attribute("y"), "%d", &y);   

    textlabel = new TextLabel(x, y, xTextLabel->Attribute("text"));
    
    if(xTextLabel->Attribute("id") != 0)
    {
      sscanf(xTextLabel->Attribute("id"), "%s", id);   
      textlabel->setId(string(id));
    }

    addGUIElement(textlabel);
  }
}
