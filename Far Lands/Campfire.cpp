#include "Campfire.h"

Campfire::Campfire(sf::Vector2f pos) : Object (ObjectType::CAMPFIRE, pos)
{
	rect.setTextureRect({ 0, 0, 32, 32 });
}

Campfire::~Campfire()
{
}

void Campfire::Touch()
{
}

void Campfire::Update()
{
}

ObjectType Campfire::GetType()
{
	return ObjectType::CAMPFIRE;
}
