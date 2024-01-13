#include "Enemy.h"
#include "EntityManager.h"

void Enemy::Drop()
{
}

Enemy::Enemy(EnemyType type, sf::Vector2f pos) : Entity(TypeConverter::Convert(type), pos)
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

void Enemy::Punch(float DMG)
{
	stats->HP -= DMG;
	if (stats->HP <= 0)
		EntityManager::GetInstance()->AddInDestroyList(ID);
}
