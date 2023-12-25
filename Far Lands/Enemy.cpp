#include "Enemy.h"

Enemy::Enemy(Type type, sf::Vector2f pos) : Entity(type, pos)
{

}

Enemy::~Enemy()
{

}

sf::FloatRect Enemy::GetBounds()
{
	return rect.getGlobalBounds();
}

void Enemy::Update()
{

}