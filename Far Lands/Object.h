#pragma once
#include "BaseValue.h"
#include "ResourceManager.h"

class Object
{
	bool collision = true;
	sf::RectangleShape rect;
	ObjectType type;
	sf::Clock clock;
	bool ready = false;

public:
	Object(ObjectType type, sf::Vector2f pos);
	void Draw(sf::RenderWindow* win);
	void SetPosition(sf::Vector2f pos);
	sf::FloatRect GetCollisionRect();
	bool GetCollision();
	void Update();
	ObjectType GetType();
	void Touch();
};

