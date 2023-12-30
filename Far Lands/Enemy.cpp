#include "Enemy.h"
#include "EntityManager.h"
#include "Stats.h"

Enemy::Enemy(Type type, sf::Vector2i pos) : Entity(type, pos)
{
	stats = new Stats(type);
	collision = true;
}

Enemy::~Enemy()
{
	delete stats;
	stats = nullptr;
}

void Enemy::Punch(float DMG)
{
	stats->HP -= DMG;
	if (stats->HP <= 0)
		EntityManager::GetInstance()->AddInDestroyList(ID);
}
