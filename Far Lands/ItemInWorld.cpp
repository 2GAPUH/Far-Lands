#include "ItemInWorld.h"
#include "EntityManager.h"

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
	distance = distanceBetweenPoints(rect.getPosition() + rect.getSize() * 0.5f, player->GetCenter());
	if (distance < player->GetMagnetDistance())
	{
		movementVector = gradualMovement(rect.getPosition(), player->GetCenter());
		if (distance < EQUIP_DISTANCE)
			count = player->PickUpItem(type, count);
		if (count == 0)
			EntityManager::GetInstance()->AddInDestroyList(ID);
	}
	else
		movementVector = { 0, 0 };

	Move();
}

ItemInWorld::ItemInWorld(Type type, sf::Vector2f pos, int count) : Entity(type, pos)
{
	player = Player::GetInstance();
	rect.setSize(ITEM_IN_WORLD_SIZE);
	this->count = count;
	this->type = type;
}

ItemInWorld::~ItemInWorld()
{
}
