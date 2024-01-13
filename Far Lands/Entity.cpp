#include "Entity.h"
#include "ResourceManager.h"
int Entity::count = 0;

void Entity::UpdateTilePos()
{
	tilePos = sf::Vector2i(rect.getPosition() / TILE_SIZE.x);
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
