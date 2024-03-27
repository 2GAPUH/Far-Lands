#include "BerryBush.h"


BerryBush::BerryBush(sf::Vector2f pos) : Object(ObjectType::BERRY_BUSH, pos)
{
	rect.setTextureRect({ 0, 0, 16, 16 });
}

BerryBush::~BerryBush()
{
	EntityManager::GetInstance()->Create(ItemType::BERRYS, rect.getPosition(), 1);
	ResourceManager::GetInstance()->PlaySound(SoundList::PLANT_BREAK);
}

bool BerryBush::Touch(ItemType type)
{
	if (ready)
	{
		clock.restart();
		ready = false;

		EntityManager::GetInstance()->Create(ItemType::BERRYS, rect.getPosition(), 3);
		rect.setTextureRect({ 0, 0, 16, 16 });
	}

	return NOT_USE;
}

void BerryBush::Update()
{
	if (clock.getElapsedTime().asSeconds() > 5)
	{
		ready = true;
		rect.setTextureRect({16, 0, 16, 16});
	}
}

ObjectType BerryBush::GetType()
{
	return ObjectType::BERRY_BUSH;
}
