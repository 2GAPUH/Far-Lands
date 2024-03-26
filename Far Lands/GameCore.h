#pragma once
#include "BaseValue.h"
#include "World.h"
#include "Player.h"
#include "EntityManager.h"

class GameCore
{
#pragma region ST
private:
    GameCore();
    GameCore(GameCore&);
    GameCore(GameCore&&);
    static GameCore* instance;
    ~GameCore();
public:
    static GameCore* GetInstance();
    static void DestroyInstance();
#pragma endregion 

private:
    sf::RenderWindow* win = nullptr;
    World* world = nullptr;
    sf::View* view = nullptr;
    static bool playerAlive;

private:
    void Update();
    void Draw();
    void Move();

    Player* player = nullptr;
    EntityManager* entityManager = nullptr;

public:
    void Start();
    sf::RenderWindow* GetWin();
    void EndGame();
};

