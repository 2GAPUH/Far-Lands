#include "Stone.h"

Stone::Stone(sf::Vector2f pos) : Object(ObjectType::STONE, pos)
{
	durability = 3;

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
	ResourceManager::GetInstance()->PlaySound(SoundList::STONE_BREAK);
}

bool Stone::Touch(ItemType type)
{
	return NOT_USE;
}

void Stone::Update()
{
}

ObjectType Stone::GetType()
{
	return ObjectType::STONE;
}