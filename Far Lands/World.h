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
	sf::Vector2i size = { 0 ,0 };
	Tile*** map = nullptr;
	bool handleCollision(sf::FloatRect& player, const sf::FloatRect& block, sf::Vector2f& shift);
	std::vector<std::vector<int>>* ReadFile(std::string path);

public:
	void Draw(sf::RenderWindow* win, sf::FloatRect tilePos);
	void SetObject(ObjectType type, sf::Vector2i pos);
	bool CheckCollision(sf::Vector2f& shift, sf::FloatRect player);
	sf::Vector2i CheckTilePos(sf::FloatRect rect);
};

