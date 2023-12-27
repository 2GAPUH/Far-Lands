#include "Object.h"

Object::Object(Type type, sf::Vector2f pos)
{
	switch (type)
	{
	case Type::WALL:
	case Type::BERRY_BUSH:
	case Type::OBJECTS:
		rect.setSize(TILE_SIZE);
		break;
	}

	rect.setPosition(pos);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
	if (type == Type::OBJECTS)
		rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
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
