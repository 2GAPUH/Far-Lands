#pragma once
#include "BaseValue.h"
#include "Stats.h"
#include "Storage.h"

class Player
{
#pragma region ST
private:
	Player();
	Player(Player&);
	Player(Player&&);
	static Player* instance;
	~Player();
public:
	static Player* GetInstance();
	static void DestroyInstance();
#pragma endregion 

private:
	Stats* stats = nullptr;
	sf::RectangleShape rect;
	sf::Vector2i tilePos = { 0 ,0 };
	void UpdateTilePosition();
	sf::Vector2f spawnTile = { 0, 0 };
	Storage* inventory = nullptr;

public:
	void SetTexture();
	void AtrackItem();
	void Interact();
	void Atack();

	void Draw(sf::RenderWindow* win);
	float GetSpeed();
	void Move(sf::Vector2f shift);
	sf::Vector2f GetCenter();
	sf::FloatRect GetPosition();
	sf::Vector2i GetTilePosition();
	float GetMagnetDistance();
	void Respawn();
	void OpenInventory();
};