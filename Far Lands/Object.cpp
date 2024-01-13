#include "Object.h"

Object::Object(ObjectType type, sf::Vector2f pos)
{
	switch (type)
	{
	case ObjectType::WALL:
	case ObjectType::BERRY_BUSH:
	case ObjectType::OBJECTS:
	case ObjectType::INVISIBLE_WALL:
		rect.setSize(TILE_SIZE);
		break;
	}

	rect.setPosition(pos);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(TypeConverter::Convert(type)));
	if (type == ObjectType::OBJECTS)
		rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(TypeConverter::Convert(type)));
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
