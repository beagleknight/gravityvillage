#ifndef CLASS_ENTITY_H
#define CLASS_ENTITY_H

#define ENTITY_GENERIC 0
#define ENTITY_PLAYER 1
#define ENTITY_MAP 2
#define ENTITY_ENEMY 3
#define ENTITY_ITEM 4
#define ENTITY_TOWN 5

class Entity
{
  public:
    Entity();
    ~Entity();
    virtual void render() = 0;
    virtual void update(float dt) = 0;
    void setType(int _type);
    int getType();
  private:
    int type;
};

#endif
