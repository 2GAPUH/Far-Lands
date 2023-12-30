#include "World.h"
World* World::instance = nullptr;

void World::Load()
{

}

World* World::GetInstance()
{
    if (instance == nullptr)
        instance = new World();
    return instance;
}

void World::DestroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

bool World::handleCollision(sf::FloatRect& player, const sf::FloatRect& block, sf::Vector2f& movementVector) {
    sf::FloatRect intersection;
    sf::FloatRect playerNew = { player.left + movementVector.x, player.top + movementVector.y, player.width, player.height };

    if (block.intersects(playerNew, intersection)) 
    {
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
                    movementVector.x += overlapX;
                }
                else {
                    movementVector.x -= overlapX;
                }
            }
            else {
                if (dy > 0) {
                    movementVector.y += overlapY;
                }
                else {
                    movementVector.y -= overlapY;
                }
            }
        }
        else {
            // Иначе корректируем только по одной оси
            if (overlapX > 0) {
                if (dx > 0) {
                    movementVector.x += overlapX;
                }
                else {
                    movementVector.x -= overlapX;
                }
            }
            if (overlapY > 0) {
                if (dy > 0) {
                    movementVector.y += overlapY;
                }
                else {
                    movementVector.y -= overlapY;
                }
            }
        }
        return true;
    }
    return false;
}

sf::Vector2i World::TilePos(sf::FloatRect rect)
{
    return { int((rect.left + rect.width / 2) / TILE_SIZE.x) ,
    int((rect.top + rect.height / 2) / TILE_SIZE.y )};
}


World::World()
{
	map = new Tile**[MAP_SIZE.x];
	for (int i = 0; i < MAP_SIZE.x; i++)
		map[i] = new Tile * [MAP_SIZE.y];

	for (int i = 0; i < MAP_SIZE.x; i++)
		for (int j = 0; j < MAP_SIZE.y; j++)
        {
            map[i][j] = new Tile(Type::GRASS, sf::Vector2i{ i, j });
            if (ResourceManager::GetInstance()->getRandomNumber(0, 30) == 0)
            {
                map[i][j]->SetObject(Type::OBJECTS);
            }
        }
}

World::~World()
{
    for (int i = 0; i < MAP_SIZE.x; i++)
        for (int j = 0; j < MAP_SIZE.y; j++)
            delete map[i][j];

    for (int i = 0; i < MAP_SIZE.x; i++)
        delete map[i];

    delete map;
    map = nullptr;
}

void World::Draw(sf::RenderWindow* win, sf::Vector2i tilePos)
{
    sf::Vector2i shift = { int(WIN_SIZE.x / TILE_SIZE.x / 2 + 1), int(WIN_SIZE.y / TILE_SIZE.y / 2 + 1) };

    int startX = std::max(0, tilePos.x - shift.x);
    int startY = std::max(0, tilePos.y - shift.y);
    int endX = std::min((int)MAP_SIZE.x, tilePos.x + shift.x + 1);
    int endY = std::min((int)MAP_SIZE.y, tilePos.y + shift.y + 1);

    for (int i = startX; i < endX; ++i)
        for (int j = startY; j < endY; ++j)
            map[i][j]->Draw(win);
}

void World::SetObject(Type type, sf::Vector2i pos)
{
	map[pos.x][pos.y]->SetObject(type);
}



bool World::CheckCollision(sf::Vector2f& movementVector, sf::FloatRect colRect)
{
    bool flag = 0;
    sf::Vector2i tilePos = TilePos(colRect);
    for (int i = tilePos.x - 1; i <= tilePos.x + 1; i++)
        for (int j = tilePos.y - 1; j <= tilePos.y + 1; j++)
            flag += handleCollision(colRect, map[i][j]->GetObjBounds(), movementVector);
    return flag;
}