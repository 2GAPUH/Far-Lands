#pragma once
#include "BaseValue.h"
#include "Object.h"
class Tile
{
	sf::RectangleShape rect;
	Object* obj = nullptr;
public:
	Tile(Type type, sf::Vector2i pos);
	void SetObject(Type type);
	void Draw(sf::RenderWindow* win);
	void Move(sf::Vector2f shift);
	sf::FloatRect GetObjBounds();
	bool CheckObject();
};

