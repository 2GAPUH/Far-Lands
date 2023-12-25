#include "Enemy.h"
#include "EntityManager.h"

void Enemy::Drop()
{
	switch (type)
	{
	case Type::CHICKEN:
		EntityManager::GetInstance()->Create(Type::CHICKEN_MEAT_RAW, rect.getPosition());
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
