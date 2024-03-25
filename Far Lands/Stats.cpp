#include "Stats.h"

void Stats::SetStats(float HP, float DMG, float defense, float speed, float money, float lucky, bool collision, int gazeDerection, float magnetDistance, int touchDistance)
{
	this->HP = HP;
	this->DMG = DMG;
	this->defense = defense;
	this->speed = speed;
	this->money = money;
	this->lucky = lucky;
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
		SetStats(PLAYER_HP, PLAYER_DMG, PLAYER_DEFENSE, PLAYER_SPEED, PLAYER_MONEY, PLAYER_LUCKY, PLAYER_COLLISION, BASE_GAZE_DERECTION, BASE_MAGNET_DISTANCE, TOUCH_DISTANCE);
		break;

	case EnemyType::CHICKEN:
		SetStats(CHICKEN_HP, CHICKEN_DMG, CHICKEN_DEFENSE, CHICKEN_SPEED, CHICKEN_MONEY, CHICKEN_LUCKY, CHICKEN_COLLISION, BASE_GAZE_DERECTION, NULL, NULL);
		break;
	}
}
