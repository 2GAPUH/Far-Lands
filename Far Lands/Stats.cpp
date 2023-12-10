#include "Stats.h"

Stats::Stats(float HP, float DMG, float defense, float speed, float money, float lucky)
{
	this->HP = HP;
	this->DMG = DMG;
	this->defense = defense;
	this->speed = speed;
	this->money = money;
	this->lucky = lucky;
}

Stats::Stats(bool collision, int gazeDerection)
{
	this->collision = collision;
	this->gazeDerection = gazeDerection;
}

Stats::Stats(EntityType type)
{
	switch (type)
	{
	case EntityType::PLAYER:
		Stats(PLAYER_HP, PLAYER_DMG, PLAYER_DEFENSE, PLAYER_SPEED, PLAYER_MONEY, PLAYER_LUCKY);
		Stats(PLAYER_COLLISION, BASE_GAZE_DERECTION);
		break;

	}
}
