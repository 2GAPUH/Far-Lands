#pragma once
#include "BaseValue.h"


class Stats
{
	Stats(float HP, float DMG, float defense, float speed, float money, float lucky);
	Stats(bool collision, int gazeDerection);

public:
	float HP = 0;
	float DMG = 0;
	float defense = 0;
	float speed = 0;
	float money = 0;
	float lucky = 0;
	bool collision = 0;
	int gazeDerection = 0;
	sf::RectangleShape rect;

	Stats(EntityType type);
};