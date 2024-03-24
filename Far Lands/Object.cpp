#include "Object.h"
#include "EntityManager.h"

Object::Object(ObjectType type, sf::Vector2f pos)
{
	this->type = type;

	rect.setSize(TILE_SIZE);
	rect.setPosition(pos);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(TypeConverter::Convert(type)));
	
	switch (type)
	{
	case ObjectType::FARMER_PLANTED:
		collision = false;
		break;
	}

	if (type == ObjectType::OBJECTS)
		rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(TypeConverter::Convert(type)));
	else if(type== ObjectType::BERRY_BUSH)
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

bool Object::GetCollision()
{
	return collision;
}

void Object::Update()
{
	if (type == ObjectType::BERRY_BUSH)
		if (clock.getElapsedTime().asSeconds() > 5)
		{
			ready = true;
			rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(TypeConverter::Convert(type), sf::Vector2i(1, 0)));
		} 
}

ObjectType Object::GetType()
{
	return type;
}

void Object::Touch()
{
	if (ready)
	{
		clock.restart();
		ready = false;

		if (type == ObjectType::BERRY_BUSH)
		{
			EntityManager::GetInstance()->Create(ItemType::BERRYS, rect.getPosition(), 3);
			rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(TypeConverter::Convert(type), sf::Vector2i(0, 0)));
		}
	}
}
