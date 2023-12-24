#pragma once
#include "BaseValue.h"
#include "Entity.h"
#include <vector>

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
    std::vector<Entity*> vect;
public:
    void Create(Type type, sf::Vector2f pos);
    void Destroy(int ID);
    void Draw(sf::RenderWindow* win);
    void Update();
};

