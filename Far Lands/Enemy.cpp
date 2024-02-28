#include "Enemy.h"
#include "EntityManager.h"

void Enemy::Drop()
{
}

Enemy::Enemy(EnemyType type, sf::Vector2f pos) : Entity(TypeConverter::Convert(type), pos)
{
	stats = new Stats(type);
	animation = new Animation(const_cast<sf::Texture*>(rect.getTexture()));
	this->type = type;
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

void Enemy::Draw(sf::RenderWindow* win)
{
	animation->Draw(viewDerection, win, rect.getPosition());
}
