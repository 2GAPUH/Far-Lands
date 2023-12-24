#include "Entity.h"
int Entity::count = 0;

Entity::Entity()
{
	count++;
	ID = count;
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
