#include "Object.h"

Object::Object(Type type, sf::Vector2f pos)
{
	switch (type)
	{
	case Type::WALL:
		rect.setSize(TILE_SIZE);
		break;
	}

	rect.setPosition(pos);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
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
