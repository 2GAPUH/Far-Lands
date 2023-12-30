#include "Chicken.h"
#include "EntityManager.h"

void Chicken::Drop()
{
	EntityManager::GetInstance()->CreateItemInWorld(Type::CHICKEN_MEAT_RAW, rect.getPosition(), 1);
}

Chicken::Chicken(sf::Vector2i tilePos) : Enemy(Type::CHICKEN, tilePos)
{

}

Chicken::~Chicken()
{
	Drop();
}

void Chicken::Update()
{

}
