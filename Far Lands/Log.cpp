#include "Log.h"

Log::Log(sf::Vector2f pos) : Object(ObjectType::LOG, pos)
{
	rect.setTextureRect({ 0, 0, 16, 16 });
}

Log::~Log()
{
	EntityManager::GetInstance()->Create(ItemType::BIG_LOG, rect.getPosition(), 1);
}

void Log::Touch()
{
}

void Log::Update()
{
}

ObjectType Log::GetType()
{
	return ObjectType::LOG;
}
