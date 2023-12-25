#pragma once
#include "Entity.h"

class Enemy :public Entity
{
	Stats*  stats = nullptr;
	void Drop();
	Type type;

public:
	Enemy(Type type, sf::Vector2f pos);
	~Enemy();
	sf::FloatRect GetBounds();
	void Update() override; 
	void Punch(float DMG);
};

