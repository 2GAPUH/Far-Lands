#pragma once
#include "Entity.h"
#include "Player.h"


class ItemInWorld :public Entity
{
private:
	Player* player = nullptr;
	float distanceBetweenPoints(sf::Vector2f point1, sf::Vector2f point2);
	sf::Vector2f gradualMovement(sf::Vector2f curPos, sf::Vector2f targetPos);
	float distance = 0;
	int count = 0;
	ItemType type;

public:
	void Update() override;
	ItemInWorld(ItemType type, sf::Vector2f pos, int count);
	~ItemInWorld();
};