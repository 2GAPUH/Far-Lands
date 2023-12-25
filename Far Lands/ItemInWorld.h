#pragma once
#include "Entity.h"


class ItemInWorld :public Entity
{
public:
	void Update() override;
	ItemInWorld(Type type, sf::Vector2f pos);
	~ItemInWorld();
};

