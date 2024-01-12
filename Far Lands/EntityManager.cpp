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

//Create enemy
void EntityManager::Create(EnemyType type, sf::Vector2f pos)
{
    if(type != EnemyType::PLAYER)
        vect.push_back(new Enemy(type, pos));
}


//Create item
void EntityManager::Create(ItemType type, sf::Vector2f pos, int count)
{
    vect.push_back(new ItemInWorld(type, pos, count));
}

//Create projectile
void EntityManager::Create(ProjectileType type, sf::Vector2f pos, sf::Vector2f aim)
{
    vect.push_back(new Projectile(type, pos, aim));
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


