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

Stats::Stats(EntityType type)
{
	switch (type)
	{
	case EntityType::PLAYER:
		SetStats(PLAYER_HP, PLAYER_DMG, PLAYER_DEFENSE, PLAYER_SPEED, PLAYER_MONEY, PLAYER_LUCKY, PLAYER_COLLISION, BASE_GAZE_DERECTION);
		break;
	}
}
