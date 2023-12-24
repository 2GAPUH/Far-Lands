#include "EntityManager.h"
#include "Enemy.h"
#include "Projectile.h"
#include "ItemInWorld.h"

EntityManager* EntityManager::instance = nullptr;

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
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

void EntityManager::Create(Type type, sf::Vector2f pos)
{
    switch (type)
    {
    case Type::ARROW:
        vect.push_back(new Projectile(type, pos));
        break;

    case Type::CHICKEN:
        vect.push_back(new Enemy(type, pos));
        break;

    case Type::APPLE:
        vect.push_back(new ItemInWorld());
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
}

