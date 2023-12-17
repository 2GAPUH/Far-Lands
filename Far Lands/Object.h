#pragma once
#include "BaseValue.h"
#include "ResourceManager.h"

class Object
{
	bool collision = true;
	sf::RectangleShape rect;

public:
	Object(ObjectType type);
	void Draw(sf::RenderWindow* win, sf::Vector2f pos);
};

