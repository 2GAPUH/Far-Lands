#include "World.h"

void World::Load()
{
}

World::World()
{
	map = new Tile**[MAP_SIZE.x];
	for (int i = 0; i < MAP_SIZE.x; i++)
		map[i] = new Tile * [MAP_SIZE.y];

	for (int i = 0; i < MAP_SIZE.x; i++)
		for (int j = 0; j < MAP_SIZE.y; j++)
			map[i][j] = new Tile(TileType::GRASS, sf::Vector2i{ i, j });
}

World::~World()
{
}

void World::Draw(sf::RenderWindow* win)
{
	for (int i = 0; i < MAP_SIZE.x; i++)
		for (int j = 0; j < MAP_SIZE.y; j++)
			map[i][j]->Draw(win);
}

void World::Move(sf::Vector2f shift)
{
	for (int i = 0; i < MAP_SIZE.x; i++)
		for (int j = 0; j < MAP_SIZE.y; j++)
			map[i][j]->Move(shift);
}
