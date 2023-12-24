#pragma once
#include "BaseValue.h"
#include "Stats.h"

class Entity
{
protected:
	sf::RectangleShape rect;
	static int count;
	int ID;
public:
	Entity();
	~Entity();
	void Draw(sf::RenderWindow* win);
	void Update();
	int GetID();
};

