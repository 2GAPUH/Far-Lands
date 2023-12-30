#pragma once
#include "BaseValue.h"
#include "Entity.h"
#include <vector>

class World;

class EntityManager
{
#pragma region ST
private:
    EntityManager();
    EntityManager(EntityManager&);
    EntityManager(EntityManager&&);
    static EntityManager* instance;
    ~EntityManager();
public:
    static EntityManager* GetInstance();
    static void DestroyInstance();
#pragma endregion
private:
    std::vector<Entity*> vect;
    std::vector<int> destroyList;
    void Destroy(int ID);
    sf::Clock clock;
    sf::Time spawnTimer;
    float spawnInterval = 2.0f;
    World* world = nullptr;
    bool CheckOutWorld(sf::Vector2i tilePos);

public:
    void CreateEnemy(Type type, sf::Vector2i tilePos);
    void CreateItemInWorld(Type type, sf::Vector2f pos, int count);
    void CreateProjectile(Type type, sf::Vector2f pos, sf::Vector2f aim);
    void Draw(sf::RenderWindow* win);
    void Update();
    void AddInDestroyList(int ID);
};

