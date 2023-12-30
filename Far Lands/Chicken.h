#pragma once
#include "Enemy.h"

class Chicken : public Enemy
{
private:
	void Drop() override;

public:
	Chicken(sf::Vector2i tilePos);
	~Chicken();
	void Update() override;
};

