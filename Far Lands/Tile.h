#pragma once
#include "BaseValue.h"
#include "Object.h"
class Tile
{
	sf::RectangleShape rect;
	Object* obj = nullptr;


public:
	Tile(Type type, sf::Vector2i pos);
	~Tile();
	void SetObject(ObjectType type);
	void Draw(sf::RenderWindow* win);
	void Move(sf::Vector2f shift);
	sf::FloatRect GetObjBounds();
	bool CheckObject();
	void Update();
	ObjectType GetObectType();
	void Touch();
	void DamageObject();
};

