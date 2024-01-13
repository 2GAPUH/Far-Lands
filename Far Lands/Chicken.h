#pragma once
#include "Enemy.h"

class Chicken : public Enemy
{
	void Drop() override;
public:
	void Update() override;
	Chicken(sf::Vector2f pos);
	~Chicken();
};

