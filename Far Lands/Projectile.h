#pragma once
#include "Entity.h"
#include "BaseValue.h"

class Projectile :public Entity
{
protected:
	float speed = 0;
	float angle = 0;
	float DMG = 0;
	void UpdateMovementVector(sf::Vector2f pos, sf::Vector2f aim);

public:
	Projectile(ProjectileType type, sf::Vector2f pos, sf::Vector2f aim);
	~Projectile();
	virtual void Update() override;
	void WorldCollision() override;
};

