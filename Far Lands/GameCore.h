#pragma once
#include "BaseValue.h"
#include "World.h"
#include "Player.h"

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
    Player* player = nullptr;

private:
    void Update();
    void Draw();
    void Move();

public:
    void Start();
    sf::RenderWindow* GetWin();
};

