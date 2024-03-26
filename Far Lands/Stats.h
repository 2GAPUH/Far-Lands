#pragma once
#include "BaseValue.h"


class Stats
{
	void SetStats(float HP, float DMG, float speed, bool collision, int gazeDerection, float magnetDistance, int touchDistance);
public:
	float HP = 0;
	float DMG = 0;
	float speed = 0;
	bool collision = 0;
	int gazeDerection = 0;
	float magnetDistance = 0;
	int touchDistance = 0;

	Stats(EnemyType type);
};