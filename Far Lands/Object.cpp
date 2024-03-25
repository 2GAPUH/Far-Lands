#include "Object.h"
#include "EntityManager.h"

Object::Object(ObjectType type, sf::Vector2f pos)
{
	rect.setSize(TILE_SIZE);
	rect.setPosition(pos);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(TypeConverter::Convert(type)));
}

Object::~Object()
{
}

void Object::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}

void Object::SetPosition(sf::Vector2f pos)
{
	rect.setPosition(pos);
}

sf::FloatRect Object::GetCollisionRect()
{
	return rect.getGlobalBounds();
}

bool Object::GetCollision()
{
	return collision;
}