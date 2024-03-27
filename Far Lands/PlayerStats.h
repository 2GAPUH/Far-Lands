#pragma once
#include "Stats.h"

class PlayerStats : public Stats
{
	sf::RectangleShape statusBar;
	sf::RectangleShape point;
	float starve;
	float energy;
	float max_value = 10;
	sf::Clock starveClock;
	sf::Clock energyClock;
	void Starve();
	void Tired();
	sf::Clock restClock;
	bool rest = false;

public:
	PlayerStats();
	~PlayerStats();
	void Draw(sf::RenderWindow* win, sf::Vector2f pos);
	void Update();
	void Damage(int i);
	void RestoreEnergy(int i);
	void Rest();
};

