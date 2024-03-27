#include "World.h"
#include <fstream>
#include <vector>
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

bool World::handleCollision(sf::FloatRect& player, const sf::FloatRect& block, sf::Vector2f& shift) {
    sf::FloatRect intersection;
    sf::FloatRect playerNew = { player.left + shift.x, player.top + shift.y, player.width, player.height };

    // Проверяем столкновение
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
                shift.x += (dx > 0) ? overlapX : -overlapX;
            }
            else {
                shift.y += (dy > 0) ? overlapY : -overlapY;
            }
        }
        else {
            // Иначе корректируем только по одной оси
            if (overlapX > 0) {
                shift.x += (dx > 0) ? overlapX : -overlapX;
            }
            if (overlapY > 0) {
                shift.y += (dy > 0) ? overlapY : -overlapY;
            }
        }
        return true;
    }
    return false;
}



std::vector<std::vector<int>>* World::ReadFile(std::string path)
{
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << path << std::endl;
        return nullptr;
    }

    int rows, columns;
    inputFile >> rows >> columns;

    static std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < columns; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();

    return &matrix;
}


World::World()
{
    std::vector<std::vector<int>>* matrix = ReadFile("Map.txt");

    if(matrix != nullptr)
    {
        size = { int(matrix->size()), int((*matrix)[0].size()) };

        map = new Tile * *[size.x];
        for (int i = 0; i < size.x; i++)
            map[i] = new Tile * [size.y];

        for (int i = 0; i < size.x; i++)
            for (int j = 0; j < size.y; j++)
            {
                if(i <= 1 || j <= 1 || i >= size.x - 2 || j >= size.y - 2)
                {
                    map[i][j] = new Tile(Type::WATER, sf::Vector2i{ i, j });
                    if((*matrix)[i][j] == 99)
                        map[i][j]->SetObject(ObjectType::INVISIBLE_WALL);
                }
                else
                {
                    map[i][j] = new Tile(Type::GRASS, sf::Vector2i{ i, j });
                }
            }

        for (int i = 0; i < matrix->size(); i++)
            (*matrix)[i].clear();
        matrix->clear();
    }

    for (int i = 0; i < 80; i++)
        SpawnRandomObject();

    music = ResourceManager::GetInstance()->GetMusic(MusicList::SPRING_DAY);
    music->setLoop(true);
    music->play();

    SetObject(ObjectType::CAMPFIRE, { 15, 15 });
}

World::~World()
{
    for (int i = 0; i < size.x; i++)
        for (int j = 0; j < size.y; j++)
            delete map[i][j];

    for (int i = 0; i < size.x; i++)
        delete map[i];

    delete map;
    map = nullptr;
}

void World::Draw(sf::RenderWindow* win, sf::FloatRect playerRect)
{
    sf::Vector2i tilePos = GetTilePos(playerRect);
    static sf::Vector2i shift = { int(WIN_SIZE.x / TILE_SIZE.x / 2 + 1), int(WIN_SIZE.y / TILE_SIZE.y / 2 + 1) };

    int startX = std::max(0, tilePos.x - shift.x);
    int startY = std::max(0, tilePos.y - shift.y);
    int endX = std::min((int)size.x, tilePos.x + shift.x + 1);
    int endY = std::min((int)size.y, tilePos.y + shift.y + 1);

    for (int i = startX; i < endX; ++i)
        for (int j = startY; j < endY; ++j)
            map[i][j]->Draw(win);
}

void World::SetObject(ObjectType type, sf::Vector2i pos)
{
	map[pos.x][pos.y]->SetObject(type);
}

CollisionInfo World::CheckCollision(sf::Vector2f& shift, sf::FloatRect object)
{
    sf::Vector2i tilePos = GetTilePos(object);
    bool flag = 0;

    if (tilePos.x <= 1 || tilePos.y <= 1 || tilePos.x >= size.x - 1 || tilePos.y >= size.y - 1)
        return CollisionInfo::OUT_WORLD;

    for (int i = tilePos.x - 1; i <= tilePos.x + 1; i++)
        for (int j = tilePos.y - 1; j <= tilePos.y + 1; j++)
        {
            sf::FloatRect tmp = map[i][j]->GetObjBounds();
            if (tmp.left == -100)
                continue;
            flag += handleCollision(object, tmp, shift);
        }

    if (flag)
        return CollisionInfo::TRUE;
    return CollisionInfo::FALSE;
}

sf::Vector2i World::GetTilePos(sf::FloatRect rect)
{
    return sf::Vector2i
    {
        int((rect.left + rect.width / 2.) / TILE_SIZE.x),
        int((rect.top + rect.height / 2.) / TILE_SIZE.y)
    };
}

sf::Vector2i World::GetTilePos(sf::Vector2f point)
{
    return sf::Vector2i
    {
        int(point.x / TILE_SIZE.x),
        int(point.y / TILE_SIZE.y)
    };
}

void World::Update()
{
    for (int i = 0; i < size.x; i++)
        for (int j = 0; j < size.y; j++)
             map[i][j]->Update();
}

ObjectType World::GetTileObjetType(sf::Vector2i pos)
{
    return map[pos.x][pos.y]->GetObectType();
}

bool World::TouchObject(sf::Vector2i pos, ItemType type)
{
    return map[pos.x][pos.y]->Touch(type);
}

void World::DamageObject(sf::Vector2i pos)
{
    map[pos.x][pos.y]->DamageObject();
}

void World::Plow(sf::Vector2i pos)
{
    map[pos.x][pos.y]->Plow();
}

void World::SpawnRandomObject()
{
    int count = 0;
    while (true || count < 10)
    {
        sf::Vector2i pos(RandomNumber::GetRandomNumber(3, size.x - 3), RandomNumber::GetRandomNumber(3, size.y - 3));
        
        if (map[pos.x][pos.y]->GetObectType() == ObjectType::EMPTY)
        {
            switch(RandomNumber::GetRandomNumber(0, 3))
            {
            case 0:
                map[pos.x][pos.y]->SetObject(ObjectType::LOG);
                break;

            case 1:
                map[pos.x][pos.y]->SetObject(ObjectType::STUMP);
                break;

            case 2:
                map[pos.x][pos.y]->SetObject(ObjectType::BERRY_BUSH);
                break;

            case 3:
                map[pos.x][pos.y]->SetObject(ObjectType::STONE);
                break;
            }

            break;
        }
        else
        {
            count++;
        }
    }
}




