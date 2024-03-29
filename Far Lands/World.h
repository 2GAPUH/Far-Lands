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
	sf::Music* music = nullptr;

public:
	void Draw(sf::RenderWindow* win, sf::FloatRect tilePos);
	void SetObject(ObjectType type, sf::Vector2i pos);
	CollisionInfo CheckCollision(sf::Vector2f& shift, sf::FloatRect player);
	sf::Vector2i GetTilePos(sf::FloatRect rect);
	sf::Vector2i GetTilePos(sf::Vector2f point);
	void Update();
	ObjectType GetTileObjetType(sf::Vector2i pos);
	bool TouchObject(sf::Vector2i pos, ItemType type);
	void DamageObject(sf::Vector2i pos);
	void Plow(sf::Vector2i pos);
	void SpawnRandomObject();
};

