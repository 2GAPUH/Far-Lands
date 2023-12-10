#pragma once
#include "BaseValue.h"

class World
{
private:
	void Load();

public:
	World();
	~World();
	void Draw();
	void Move(sf::Vector2f shift);
};

