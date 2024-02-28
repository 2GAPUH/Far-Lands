#include "Chicken.h"
#include "EntityManager.h"

void Chicken::Drop()
{
	int count = RandomNumber::GetRandomNumber(0, 2);
	if (count != 0)
		EntityManager::GetInstance()->Create(ItemType::CHICKEN_MEAT_RAW, rect.getPosition(), count);
}

void Chicken::Update()
{
	CheckViewDerection();
	rect.move(movementVector);
}

Chicken::Chicken(sf::Vector2f pos) : Enemy(EnemyType::CHICKEN, pos)
{
	movementVector = { 1, 1 };
}

Chicken::~Chicken()
{
	Drop();
}
