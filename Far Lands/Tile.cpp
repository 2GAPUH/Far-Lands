#include "Tile.h"
#include "ResourceManager.h"

Tile::Tile(Type type, sf::Vector2i pos)
{
	rect.setPosition(pos.x * TILE_SIZE.x, pos.y * TILE_SIZE.y);
	rect.setSize(TILE_SIZE);

	switch (type)
	{
	case Type::GRASS:
		break;
	}
	
	rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
}

void Tile::SetObject(Type type)
{
	obj = new Object(type, rect.getPosition());
}

void Tile::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
	if(obj != nullptr)
		obj->Draw(win);
}

void Tile::Move(sf::Vector2f shift)
{
	rect.move(shift);
	if (obj != nullptr)
		obj->SetPosition(rect.getPosition());
}

sf::FloatRect Tile::GetObjBounds()
{
	if (obj != 0)
		return obj->GetCollisionRect();
	else
		return { -10000, -10000, 1, 1 };
}

bool Tile::CheckObject()
{
	if (obj == nullptr)
		return 0;
	return 1;
}


