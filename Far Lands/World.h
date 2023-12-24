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
	void handleCollision(sf::FloatRect& player, const sf::FloatRect& block, sf::Vector2f& shift);

public:
	World();
	~World();
	void Draw(sf::RenderWindow* win);
	void SetObject(Type type, sf::Vector2i pos);
	void CheckCollision(sf::Vector2f& shift, sf::FloatRect player, sf::Vector2i tilePos);
};

