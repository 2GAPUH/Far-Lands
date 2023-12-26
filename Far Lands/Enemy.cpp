#include "Enemy.h"
#include "EntityManager.h"
#include "ResourceManager.h"

void Enemy::Drop()
{
	int count = ResourceManager::GetInstance()->getRandomNumber(0, 2);
	if(count != 0)
	switch (type)
	{
	case Type::CHICKEN:
		EntityManager::GetInstance()->CreateItemInWorld(Type::CHICKEN_MEAT_RAW, rect.getPosition(),count );
		break;
	}
}

Enemy::Enemy(Type type, sf::Vector2f pos) : Entity(type, pos)
{
	this->type = type;
	stats = new Stats(type);
}



Enemy::~Enemy()
{
	Drop();
	delete stats;
	stats = nullptr;
}

sf::FloatRect Enemy::GetBounds()
{
	return rect.getGlobalBounds();
}

void Enemy::Update()
{

}

void Enemy::Punch(float DMG)
{
	stats->HP -= DMG;
	if (stats->HP <= 0)
		EntityManager::GetInstance()->AddInDestroyList(ID);
}
