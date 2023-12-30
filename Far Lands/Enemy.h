#pragma once
#include "Entity.h"

class Stats;
class Enemy :public Entity
{
private:
	Stats*  stats = nullptr;
	virtual  void Drop() = 0;

public:
	Enemy(Type type, sf::Vector2i pos);
	~Enemy();
	virtual void Update() = 0;
	void Punch(float DMG);
};

