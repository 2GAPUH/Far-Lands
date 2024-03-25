#include "Stone.h"

Stone::Stone(sf::Vector2f pos) : Object(ObjectType::STONE, pos)
{
	switch (RandomNumber::GetRandomNumber(0, 1))
	{
	case 1:
		rect.setTextureRect({ 0, 0, 16, 16 });
		break;

	case 0:
		rect.setTextureRect({ 16, 0, 16, 16 });
		break;
	}
}

Stone::~Stone()
{
	EntityManager::GetInstance()->Create(ItemType::STONE, rect.getPosition(), 1);
}

void Stone::Touch()
{
}

void Stone::Update()
{
}

ObjectType Stone::GetType()
{
	return ObjectType::STONE;
}