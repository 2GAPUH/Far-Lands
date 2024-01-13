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

    if (block.intersects(playerNew, intersection)) 
    {
        // ������������ ����������� �� ���� X � Y
        float overlapX = intersection.width;
        float overlapY = intersection.height;

        // ���������� ����������� �����������
        float dx = player.left - block.left;
        float dy = player.top - block.top;

        // ������������ ������ �������� �� ����� ����, ���� ���� ����������� �� ����� ����
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
            // ����� ������������ ������ �� ����� ���
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
                map[i][j] = new Tile(Type::GRASS, sf::Vector2i{ i, j });

                switch ((*matrix)[i][j])
                {
                case 99:
                    map[i][j]->SetObject(ObjectType::INVISIBLE_WALL);
                    break;
                case 0:
                    if (RandomNumber::GetRandomNumber(0, 30) == 0)
                    {
                        map[i][j]->SetObject(ObjectType::OBJECTS);
                    }
                    break;
                }
            }

        for (int i = 0; i < matrix->size(); i++)
            (*matrix)[i].clear();
        matrix->clear();
    }
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

void World::Draw(sf::RenderWindow* win, sf::Vector2i tilePos)
{
    sf::Vector2i shift = { int(WIN_SIZE.x / TILE_SIZE.x / 2 + 1), int(WIN_SIZE.y / TILE_SIZE.y / 2 + 1) };

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

bool World::CheckCollision(sf::Vector2f& shift, sf::FloatRect player, sf::Vector2i tilePos)
{
    bool flag = 0;
    for (int i = tilePos.x - 1; i <= tilePos.x + 1; i++)
        for (int j = tilePos.y - 1; j <= tilePos.y + 1; j++)
            flag += handleCollision(player, map[i][j]->GetObjBounds(), shift);
    return flag;
}



