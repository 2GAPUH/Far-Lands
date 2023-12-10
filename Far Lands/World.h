#pragma once
#include "BaseValue.h"
#include "Tile.h"

class World
{
private:
	void Load();
	int time = 0;
	sf::Vector2f size = { 0 ,0 };
	Tile*** map = nullptr;

public:
	World();
	~World();
	void Draw(sf::RenderWindow* win);
	void Move(sf::Vector2f shift);
};

