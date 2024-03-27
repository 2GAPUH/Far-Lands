#include "InvisibleWall.h"

InvisibleWall::InvisibleWall(sf::Vector2f pos) : Object(ObjectType::INVISIBLE_WALL, pos)
{
	durability = 10000;
}

InvisibleWall::~InvisibleWall()
{
}

bool InvisibleWall::Touch(ItemType type)
{
	return NOT_USE;
}

void InvisibleWall::Update()
{
}

ObjectType InvisibleWall::GetType()
{
	return ObjectType();
}
