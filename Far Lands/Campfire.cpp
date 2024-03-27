#include "Campfire.h"

Campfire::Campfire(sf::Vector2f pos) : Object (ObjectType::CAMPFIRE, pos)
{
	animation = new Animation(ResourceManager::GetInstance()->GetTexture(Type::CAMPFIRE), { 32, 32 }, 5, {TILE_SIZE.x/32.f, TILE_SIZE.y /32.f});
}

Campfire::~Campfire()
{
}

void Campfire::Touch()
{
}

void Campfire::Update()
{
}

ObjectType Campfire::GetType()
{
	return ObjectType::CAMPFIRE;
}

void Campfire::Draw(sf::RenderWindow* win)
{
	animation->Draw(status, win, rect.getPosition());
}


