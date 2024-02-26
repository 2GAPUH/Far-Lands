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
private:
    friend class Projectile;
    std::vector<Entity*> vect;
    std::vector<int> destroyList;
    void Destroy(int ID);

public:
    void Create(EnemyType type, sf::Vector2f pos);
    void Create(ItemType type, sf::Vector2f pos, int count);
    void Create(ProjectileType type, sf::Vector2f pos, sf::Vector2f aim);
    void Draw(sf::RenderWindow* win);
    void Update();
    void AddInDestroyList(int ID);

    class Iterator
    {
    private:
        std::vector<Entity*>::iterator iter;

    public:
        Iterator(std::vector<Entity*>::iterator ptr) : iter(ptr) {}

        Entity*& operator*() { return *iter; }

        Iterator& operator++() { ++iter; return *this; }

        bool operator!=(const Iterator& other) const { return iter != other.iter; }
    };

    Iterator begin() {
        return Iterator(vect.begin());
    }

    Iterator end() {
        return Iterator(vect.end());
    }
};

