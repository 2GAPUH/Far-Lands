#pragma once
#include "Entity.h"
#include "BaseValue.h"


class Enemy :public Entity
{
protected:
	Stats*  stats = nullptr;
	virtual void Drop() = 0;
	EnemyType type;
	

public:
	Enemy(EnemyType type, sf::Vector2f pos);
	~Enemy();
	sf::FloatRect GetBounds();
	virtual void Update() override = 0; 
	void Punch(float DMG);
};