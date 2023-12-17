#include "Object.h"

Object::Object(ObjectType type)
{
	switch (type)
	{
	case ObjectType::FENCE:
		rect.setTexture(ResourceManager::GetInstance()->GetTexture(TextureType::FENCE));
		rect.setSize(TILE_SIZE);
		break;
	}
}

void Object::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	rect.setPosition(pos);
	win->draw(rect);
}
