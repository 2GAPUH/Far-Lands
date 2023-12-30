#include "EntityManager.h"
#include "ResourceManager.h"
#include "ItemInWorld.h"
#include "Arrow.h"
#include "World.h" 
#include "Chicken.h"

EntityManager* EntityManager::instance = nullptr;

EntityManager::EntityManager()
{
    world = World::GetInstance();
}

EntityManager::~EntityManager()
{
    vect.clear();
}

EntityManager* EntityManager::GetInstance()
{
    if (instance == nullptr)
        instance = new EntityManager();
    return instance;
}

void EntityManager::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

bool EntityManager::CheckOutWorld(sf::Vector2i tilePos)
{
    return (tilePos.x <= 1 || tilePos.y <= 1 || tilePos.x >= MAP_SIZE.x - 2 || tilePos.y >= MAP_SIZE.y - 2);
}

void EntityManager::CreateEnemy(Type type, sf::Vector2i tilePos)
{
    switch (type)
    {
    case Type::CHICKEN:
        vect.push_back(new Chicken(tilePos));
        break;
    }
}

void EntityManager::CreateItemInWorld(Type type, sf::Vector2f pos, int count)
{
    vect.push_back(new ItemInWorld(type, pos, count));
}

void EntityManager::CreateProjectile(Type type, sf::Vector2f pos, sf::Vector2f aim)
{
    switch (type)
    {
    case Type::ARROW:
        vect.push_back(new Arrow(pos, aim));
        break;
    }
}

void EntityManager::Destroy(int ID)
{
    for (auto elem = vect.begin(); elem != vect.end(); elem++)
        if ((*elem)->GetID() == ID)
        {
            delete (*elem);
            vect.erase(elem);
            return;
        }
}

void EntityManager::Draw(sf::RenderWindow* win)
{
    for (auto elem : vect)
        elem->Draw(win);
}

void EntityManager::Update()
{
    for (auto elem : vect)
    {
        if (elem->GetCollision())
            world->CheckCollision(elem->GetMovementVector(), elem->GetBounds());
        elem->Update();
        if (CheckOutWorld(elem->GetTilePos()))
            AddInDestroyList(elem->GetID());
    }

    for (auto ID : destroyList)
    {
        Destroy(ID);
    }
    destroyList.clear();

    sf::Time deltaTime = clock.restart();
    spawnTimer += deltaTime;

    if (spawnTimer.asSeconds() >= spawnInterval) {
        CreateEnemy(Type::CHICKEN, sf::Vector2i (ResourceManager::GetInstance()->getRandomNumber(2, 20), 
            ResourceManager::GetInstance()->getRandomNumber(2, 20)));
        spawnTimer = sf::Time::Zero; 
    }
}

void EntityManager::AddInDestroyList(int ID)
{
    destroyList.push_back(ID);
}


