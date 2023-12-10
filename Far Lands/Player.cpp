#include "Player.h"

Player::Player()
{
	stats = new Stats(EntityType::PLAYER);
}

Player::~Player()
{
	delete stats;
	stats = nullptr;
}
