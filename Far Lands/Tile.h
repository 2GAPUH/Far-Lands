#pragma once
#include "BaseValue.h"

class Tile
{
	sf::RectangleShape rect;

public:
	Tile(TileType type, sf::Vector2i pos);
	void Draw(sf::RenderWindow* win);
};

