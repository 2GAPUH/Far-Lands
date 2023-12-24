#include "World.h"

void World::Load()
{
}

void World::handleCollision(sf::FloatRect& player, const sf::FloatRect& block, sf::Vector2f& shift) {
    sf::FloatRect intersection;
    sf::FloatRect playerNew = { player.left + shift.x, player.top + shift.y, player.width, player.height };

    if (block.intersects(playerNew, intersection)) {
        // Рассчитываем пересечение по осям X и Y
        float overlapX = intersection.width;
        float overlapY = intersection.height;

        // Определяем направление пересечения
        float dx = player.left - block.left;
        float dy = player.top - block.top;

        // Корректируем вектор движения по обеим осям, если есть пересечение по обеим осям
        if (overlapX > 0 && overlapY > 0) {
            if (overlapX < overlapY) {
                if (dx > 0) {
                    shift.x += overlapX;
                }
                else {
                    shift.x -= overlapX;
                }
            }
            else {
                if (dy > 0) {
                    shift.y += overlapY;
                }
                else {
                    shift.y -= overlapY;
                }
            }
        }
        else {
            // Иначе корректируем только по одной оси
            if (overlapX > 0) {
                if (dx > 0) {
                    shift.x += overlapX;
                }
                else {
                    shift.x -= overlapX;
                }
            }
            if (overlapY > 0) {
                if (dy > 0) {
                    shift.y += overlapY;
                }
                else {
                    shift.y -= overlapY;
                }
            }
        }
    }
}


World::World()
{
	map = new Tile**[MAP_SIZE.x];
	for (int i = 0; i < MAP_SIZE.x; i++)
		map[i] = new Tile * [MAP_SIZE.y];

	for (int i = 0; i < MAP_SIZE.x; i++)
		for (int j = 0; j < MAP_SIZE.y; j++)
			map[i][j] = new Tile(Type::GRASS, sf::Vector2i{ i, j });
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

void World::SetObject(Type type, sf::Vector2i pos)
{
	map[pos.x][pos.y]->SetObject(type);
}

void World::CheckCollision(sf::Vector2f& shift, sf::FloatRect player, sf::Vector2i tilePos)
{
    for (int i = tilePos.x - 2; i <= tilePos.x + 2; i++)
        for (int j = tilePos.y - 2; j <= tilePos.y + 2; j++)
            handleCollision(player, map[i][j]->GetObjBounds(), shift);
}



