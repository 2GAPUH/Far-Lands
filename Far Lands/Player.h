#pragma once
#include "BaseValue.h"
#include "Stats.h"

class Player
{
private:
	Stats* stats = nullptr;
	sf::RectangleShape rect;

public:
	Player();
	~Player();
	void SetTexture();
	void AtrackItem();
	void Interact();
	void Atack();
	void Draw(sf::RenderWindow* win);
	float GetSpeed();
};