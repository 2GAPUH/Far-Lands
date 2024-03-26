#pragma once
#include "Entity.h"
#include "BaseValue.h"
#include "Animation.h"
#include "ResourceManager.h"

class Enemy :public Entity
{
protected:
	Stats*  stats = nullptr;
	virtual void Drop() = 0;
	EnemyType type;
	Animation* animation = nullptr;

public:
	Enemy(EnemyType type, sf::Vector2f pos);
	~Enemy();
	sf::FloatRect GetBounds();
	virtual void Update() override = 0; 
	void Punch(float DMG);
	void Draw(sf::RenderWindow* win);
};