#include "Entity.hpp"

Entity::Entity()
{
  type = ENTITY_GENERIC;
  id = "unknown";
}

Entity::~Entity()
{

}

void Entity::setType(int _type)
{
  type = _type;
}

int Entity::getType()
{
  return type;
}

void Entity::setId(string _id)
{
  id = _id;
}

string Entity::getId()
{
  return id;
}
