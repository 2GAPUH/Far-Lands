#pragma once
#include "Entity.h"

class Enemy :public Entity
{
	Stats*  stats = nullptr;
public:
	Enemy(Type type, sf::Vector2f pos);
	~Enemy();
};

