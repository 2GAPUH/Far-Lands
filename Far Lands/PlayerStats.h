#pragma once
#include "Stats.h"

class PlayerStats : public Stats
{
	sf::RectangleShape statusBar;
	sf::RectangleShape point;
	float starve;
	float energy;

public:
	PlayerStats();
	~PlayerStats();
	void Draw(sf::RenderWindow* win, sf::Vector2f pos);
	void Update();
};

