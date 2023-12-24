#include "Stats.h"

void Stats::SetStats(float HP, float DMG, float defense, float speed, float money, float lucky, bool collision, int gazeDerection)
{
	this->HP = HP;
	this->DMG = DMG;
	this->defense = defense;
	this->speed = speed;
	this->money = money;
	this->lucky = lucky;
	this->collision = collision;
	this->gazeDerection = gazeDerection;
}

Stats::Stats(Type type)
{
	switch (type)
	{
	case Type::PLAYER:
		SetStats(PLAYER_HP, PLAYER_DMG, PLAYER_DEFENSE, PLAYER_SPEED, PLAYER_MONEY, PLAYER_LUCKY, PLAYER_COLLISION, BASE_GAZE_DERECTION);
		break;

	case Type::CHICKEN:
		SetStats(CHICKEN_HP, CHICKEN_DMG, CHICKEN_DEFENSE, CHICKEN_SPEED, CHICKEN_MONEY, CHICKEN_LUCKY, CHICKEN_COLLISION, BASE_GAZE_DERECTION);
		break;

	}
}
