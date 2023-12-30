#pragma once
#include "Entity.h"
#include "BaseValue.h"

class Projectile :public Entity
{
protected:
	float speed = 0;
	void UpdateMovementVector(sf::Vector2f pos, sf::Vector2f aim);
	float angle = 0;
	float DMG = 0;
	void SetValues (Type type);

public:
	Projectile(Type type, sf::Vector2f pos, sf::Vector2f aim);
	~Projectile();
};

