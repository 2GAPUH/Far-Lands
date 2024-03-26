#include "Stats.h"

void Stats::SetStats(float HP, float DMG, float speed, bool collision, int gazeDerection, float magnetDistance, int touchDistance)
{
	this->HP = HP;
	this->DMG = DMG;
	this->speed = speed;
	this->collision = collision;
	this->gazeDerection = gazeDerection;
	this->magnetDistance = magnetDistance;
	this->touchDistance = touchDistance;
}

Stats::Stats(EnemyType type)
{
	switch (type)
	{
	case EnemyType::PLAYER:
		SetStats(PLAYER_HP, PLAYER_DMG, PLAYER_SPEED, PLAYER_COLLISION, BASE_GAZE_DERECTION, BASE_MAGNET_DISTANCE, TOUCH_DISTANCE);
		break;

	case EnemyType::CHICKEN:
		SetStats(CHICKEN_HP, CHICKEN_DMG, CHICKEN_SPEED, CHICKEN_COLLISION, BASE_GAZE_DERECTION, NULL, NULL);
		break;
	}
}
