#include "Projectile.h"
#include "ResourceManager.h"

Projectile::Projectile(Type type, sf::Vector2f pos)
{
	switch (type)
	{
	case Type::ARROW:
		break;

	}

	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	rect.setPosition(pos);
}
