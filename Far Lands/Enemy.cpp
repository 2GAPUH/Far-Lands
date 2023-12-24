#include "Enemy.h"
#include "ResourceManager.h"

Enemy::Enemy(Type type, sf::Vector2f pos)
{

	switch (type)
	{
	case Type::CHICKEN:
		rect.setSize(CHICKEN_SIZE);
		break;
	}

	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	stats = new Stats(type);
	rect.setPosition(pos);
}
