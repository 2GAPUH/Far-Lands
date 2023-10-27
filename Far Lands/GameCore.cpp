#include "GameCore.h"

GameCore* GameCore::instance = nullptr;

GameCore::GameCore() {}

GameCore::~GameCore() {}

GameCore* GameCore::Get_Instance()
{
    if (instance == nullptr)
        instance = new GameCore();
    return instance;
}

void GameCore::Destroy_Instance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}