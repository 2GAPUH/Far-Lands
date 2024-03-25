#include "Stump.h"

Stump::Stump(sf::Vector2f pos) : Object(ObjectType::STUMP, pos)
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

Stump::~Stump()
{
	EntityManager::GetInstance()->Create(ItemType::SMALL_LOG, rect.getPosition(), 1);
}

void Stump::Touch()
{
}

void Stump::Update()
{
}

ObjectType Stump::GetType()
{
	return ObjectType::STUMP;
}
