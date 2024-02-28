#include "Entity.h"
#include "ResourceManager.h"
int Entity::count = 0;

void Entity::UpdateTilePos()
{
	tilePos = sf::Vector2i(rect.getPosition() / TILE_SIZE.x);
}

void Entity::CheckViewDerection()
{
	if (movementVector == sf::Vector2f{ 0, 0 })
	{
		viewDerection = StateType::IDLE;
		return;
	}
	if (movementVector.x > 0)
		viewDerection = StateType::RIGHT;
	else if (movementVector.x < 0)
		viewDerection = StateType::LEFT;
	else if (movementVector.y != 0)
		viewDerection = StateType::RIGHT;
}

Entity::Entity(Type type, sf::Vector2f pos)
{
	count++;
	ID = count;

	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	//rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
	rect.setPosition(pos);
	rect.setSize(TILE_SIZE);
	UpdateTilePos();
}

Entity::~Entity()
{

}

void Entity::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}

int Entity::GetID()
{
	return ID;
}

sf::Vector2f& Entity::GetMovementVector()
{
	return movementVector;
}

sf::FloatRect Entity::GetGlobalBounds()
{
	return rect.getGlobalBounds();
}

void Entity::WorldCollision()
{
}