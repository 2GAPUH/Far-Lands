#pragma once
#include "BaseValue.h"
#include "Tile.h"

class World
{
#pragma region ST
private:
	World();
	World(World&);
	World(World&&);
	static World* instance;
	~World();
public:
	static World* GetInstance();
	static void DestroyInstance();
#pragma endregion 

private:
	void Load();
	int time = 0;
	sf::Vector2f size = { 0 ,0 };
	Tile*** map = nullptr;
	bool handleCollision(sf::FloatRect& player, const sf::FloatRect& block, sf::Vector2f& movementVector);
	sf::Vector2i TilePos(sf::FloatRect rect);

public:
	void Draw(sf::RenderWindow* win, sf::Vector2i tilePos);
	void SetObject(Type type, sf::Vector2i pos);
	bool CheckCollision(sf::Vector2f& movementVector, sf::FloatRect collisionRect);
};

