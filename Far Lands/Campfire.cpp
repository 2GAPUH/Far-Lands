#include "Campfire.h"
#include "Player.h"


Campfire::Campfire(sf::Vector2f pos) : Object (ObjectType::CAMPFIRE, pos)
{
	animation = new Animation(ResourceManager::GetInstance()->GetTexture(Type::CAMPFIRE), { 48, 48 }, 5, {1, 1});
	durability = 5;
	activeRect = { pos.x + TILE_SIZE.x / 2.f - TILE_SIZE.x * CAMPFIRE_ACTIVE_TILE_RENGE, pos.y + TILE_SIZE.y / 2.f - TILE_SIZE.y * CAMPFIRE_ACTIVE_TILE_RENGE, 0, 0 };
	activeRect.width = TILE_SIZE.x * CAMPFIRE_ACTIVE_TILE_RENGE * 2;
	activeRect.height = TILE_SIZE.y * CAMPFIRE_ACTIVE_TILE_RENGE * 2;
}

Campfire::~Campfire()
{
}

bool Campfire::Touch(ItemType type)
{
	switch (type)
	{
	case ItemType::BIG_LOG:
		burningTime += BIG_LOG_BURNING_TIME;
		status = StatusType::ENABLE;
		clock.restart();
		ResourceManager::GetInstance()->PlaySound(SoundList::ADD_FUEL);
		return USE;
		break;

	case ItemType::SMALL_LOG:
		burningTime += SMALL_LOG_BURNING_TIME;
		status = StatusType::ENABLE;
		clock.restart();
		ResourceManager::GetInstance()->PlaySound(SoundList::ADD_FUEL);
		return USE;
		break;
	}

	return NOT_USE;
}

void Campfire::Update()
{
	if (burningTime > 0)
	{
		burningTime -= clock.getElapsedTime().asSeconds();
		clock.restart();
	}
	else if (burningTime < 0)
	{
		burningTime = 0;
		status = StatusType::DISABLE;
	}

	if(status == StatusType::ENABLE)
	{
		if (activeRect.contains(Player::GetInstance()->GetCenter()))
			Player::GetInstance()->Rest();
	}
}

ObjectType Campfire::GetType()
{
	return ObjectType::CAMPFIRE;
}

void Campfire::Draw(sf::RenderWindow* win)
{
	animation->Draw(status, win, rect.getPosition());
}


