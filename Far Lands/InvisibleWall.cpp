#include "InvisibleWall.h"

InvisibleWall::InvisibleWall(sf::Vector2f pos) : Object(ObjectType::INVISIBLE_WALL, pos)
{
	durability = 10000;
}

InvisibleWall::~InvisibleWall()
{
}

void InvisibleWall::Touch()
{
}

void InvisibleWall::Update()
{
}

ObjectType InvisibleWall::GetType()
{
	return ObjectType();
}
