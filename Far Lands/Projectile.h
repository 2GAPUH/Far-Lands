#pragma once
#include "Entity.h"
#include "BaseValue.h"

class Projectile :public Entity
{
public:
	Projectile(Type type, sf::Vector2f pos);
	~Projectile();

};

