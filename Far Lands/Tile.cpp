#include "Tile.h"
#include "ResourceManager.h"

Tile::Tile(TileType type, sf::Vector2i pos)
{
	rect.setPosition(pos.x * TILE_SIZE.x, pos.y * TILE_SIZE.y);
	rect.setSize(TILE_SIZE);

	switch (type)
	{
	case TileType::GRASS:
		rect.setTexture(ResourceManager::GetInstance()->GetTexture(TextureType::GRASS));
		break;
	}
}

void Tile::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}
