#pragma once
#include "BaseValue.h"

class Entity
{
protected:
	sf::RectangleShape rect;
	static int count;
	int ID;
	sf::Vector2i tilePos = {0 ,0};
	bool collision = false;
	sf::Vector2f movementVector = {0 ,0};
	void UpdateTilePos();
	void Move();

public:
	Entity(Type type, sf::Vector2i tilePos);
	Entity(Type type, sf::Vector2f pos);
	virtual ~Entity();
	void Draw(sf::RenderWindow* win);
	virtual void Update() = 0;
	int GetID();
	bool GetCollision();
	sf::Vector2i GetTilePos();
	//sf::FloatRect GetCollisionRect();
	sf::Vector2f& GetMovementVector();
	sf::FloatRect GetBounds();
};

