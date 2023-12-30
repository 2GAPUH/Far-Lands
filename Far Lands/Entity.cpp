#include "Entity.h"
#include "ResourceManager.h"

int Entity::count = 0;

void Entity::UpdateTilePos()
{
	tilePos.x = (rect.getPosition().x + rect.getSize().x / 2) / TILE_SIZE.x;
	tilePos.y = (rect.getPosition().y + rect.getSize().y / 2) / TILE_SIZE.y;
}

void Entity::Move()
{
	rect.move(movementVector);
}

Entity::Entity(Type type, sf::Vector2i tilePos)
{
	count++;
	ID = count;

	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
	rect.setPosition((sf::Vector2f)tilePos * TILE_SIZE.x);
	rect.setSize(TILE_SIZE);
}

Entity::Entity(Type type, sf::Vector2f pos)
{
	count++;
	ID = count;

	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	//rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
	rect.setPosition(pos);
	rect.setSize(TILE_SIZE);
}

Entity::~Entity(){}

void Entity::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}

int Entity::GetID()
{
	return ID;
}

bool Entity::GetCollision()
{
	return collision;
}

sf::Vector2i Entity::GetTilePos()
{
	UpdateTilePos();
	return tilePos;
}

//sf::FloatRect Entity::GetCollisionRect()
//{
//	return sf::FloatRect();
//}

sf::Vector2f& Entity::GetMovementVector()
{
	return movementVector;
}

sf::FloatRect Entity::GetBounds()
{
	return rect.getGlobalBounds();
}
