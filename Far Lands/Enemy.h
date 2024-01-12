#pragma once
#include "Entity.h"

class Enemy :public Entity
{
private:
	Stats*  stats = nullptr;
	void Drop();
	EnemyType type;

public:
	Enemy(EnemyType type, sf::Vector2f pos);
	~Enemy();
	sf::FloatRect GetBounds();
	void Update() override; 
	void Punch(float DMG);
};

