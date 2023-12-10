#include "Tile.h"

Tile::Tile(TileType type, sf::Vector2f pos)
{
	rect.setPosition(pos);

	switch (type)
	{
	case TileType::GRASS:
		break;
	}
}

void Tile::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}
