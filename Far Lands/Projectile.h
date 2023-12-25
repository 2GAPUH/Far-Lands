#pragma once
#include "Entity.h"
#include "BaseValue.h"

class Projectile :public Entity
{
	float speed = 0;
	sf::Vector2f movementVector = { 0 ,0 };
	void UpdateMovementVector(sf::Vector2f pos, sf::Vector2f aim);
	float angle = 0;
	float DMG = 0;

public:
	Projectile(Type type, sf::Vector2f pos, sf::Vector2f aim);
	~Projectile();
	void Update() override;
};

