#include "EntityManager.h"
#include "ItemInWorld.h"
#include "Chicken.h"
#include "Arrow.h"

EntityManager* EntityManager::instance = nullptr;

EntityManager::EntityManager()
{
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

void EntityManager::Create(EnemyType type, sf::Vector2f pos)
{
    switch (type)
    {
    case EnemyType::CHICKEN:
        vect.push_back(new Chicken(pos));
        break;
    
    case EnemyType::PLAYER:
        break;
    }
}

void EntityManager::Create(ItemType type, sf::Vector2f pos, int count)
{
    vect.push_back(new ItemInWorld(type, pos, count));
}

void EntityManager::Create(ProjectileType type, sf::Vector2f pos, sf::Vector2f aim)
{
    switch (type)
    {
    case ProjectileType::ARROW:
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
        elem->Update();
    }

    for (auto ID : destroyList)
    {
        Destroy(ID);
    }
    destroyList.clear();


}

void EntityManager::AddInDestroyList(int ID)
{
    destroyList.push_back(ID);
}


