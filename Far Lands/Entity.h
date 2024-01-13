#pragma once
#include "BaseValue.h"
#include "Stats.h"

class Entity
{
protected:
	sf::RectangleShape rect;
	static int count;
	int ID;
	sf::Vector2i tilePos;
	void UpdateTilePos();
	sf::Vector2i GetTilePos();

public:
	Entity(Type type, sf::Vector2f pos);
	virtual ~Entity();
	void Draw(sf::RenderWindow* win);
	virtual void Update() = 0;
	int GetID();
};

