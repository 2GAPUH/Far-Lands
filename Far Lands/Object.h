#pragma once
#include "BaseValue.h"
#include "ResourceManager.h"
#include "EntityManager.h"

class Object
{
protected:
	bool collision = true;
	sf::RectangleShape rect;
	int durability = 1;

public:
	Object(ObjectType type, sf::Vector2f pos);
	virtual ~Object();
	void Draw(sf::RenderWindow* win);
	void SetPosition(sf::Vector2f pos);
	sf::FloatRect GetCollisionRect();
	bool GetCollision();
	virtual ObjectType GetType() = 0;
	virtual void Update() = 0;
	virtual void Touch() = 0;
};

