#include "Entity.h"
#include "ResourceManager.h"
int Entity::count = 0;

Entity::Entity(Type type, sf::Vector2f pos)
{
	count++;
	ID = count;

	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	//rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
	rect.setPosition(pos);
	rect.setSize(TILE_SIZE);
}

Entity::~Entity()
{

}

void Entity::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}

void Entity::Update()
{
}

int Entity::GetID()
{
	return ID;
}
