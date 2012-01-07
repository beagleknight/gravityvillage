#include "Entity.hpp"

Entity::Entity()
{
  type = ENTITY_GENERIC;
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
