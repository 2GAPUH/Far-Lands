#include "ItemInWorld.h"


float ItemInWorld::distanceBetweenPoints(sf::Vector2f point1, sf::Vector2f point2) 
{
	return std::sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
}

sf::Vector2f ItemInWorld::gradualMovement(sf::Vector2f curPos, sf::Vector2f targetPos)
{
	sf::Vector2f direction = targetPos - curPos;

	direction = direction / distance;

	return  direction * (ITEM_PICK_UP_SPEED * (1.0f - distance / player->GetMagnetDistance()));
}

void ItemInWorld::Update()
{
	distance = distanceBetweenPoints(rect.getPosition(), player->GetCenter());
	if (distance < player->GetMagnetDistance())
	{
		shift = gradualMovement(rect.getPosition(), player->GetCenter());
	}
	else
		shift = { 0, 0 };

	rect.move(shift);
}

ItemInWorld::ItemInWorld(Type type, sf::Vector2f pos) : Entity(type, pos)
{
	player = Player::GetInstance();
	rect.setSize({ 32, 32 });
}

ItemInWorld::~ItemInWorld()
{
}
