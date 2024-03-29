#pragma once
#include "BaseValue.h"
#include "PlayerStats.h"
#include "Inventory.h"
#include "EntityManager.h"
#include "Animation.h"

class World;
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
	PlayerStats* stats = nullptr;
	sf::RectangleShape rect;
	sf::Vector2f spawnTile = { 0, 0 };
	Inventory* inventory = nullptr;
	EntityManager* entityManager = nullptr;
	World* world = nullptr;
	StateType viewDerection = StateType::DOWN;
	Animation* animation = nullptr;

public:
	void ChangeHero();
	void Use(sf::Vector2f mousePos);

	void Draw(sf::RenderWindow* win);
	float GetSpeed();
	void Move(sf::Vector2f shift);
	void CheckViewDerection(sf::Vector2f shift);
	sf::Vector2f GetCenter();
	sf::FloatRect GetPosition();
	float GetMagnetDistance();
	void Respawn();
	void OpenInventory();
	int PickUpItem(ItemType type, int count);
	void EditCurLine();
	void EditCurElem(int i);
	void Update(sf::RenderWindow* win);
	void Rest();

};