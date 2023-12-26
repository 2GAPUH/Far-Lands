#pragma once
#include "BaseValue.h"

class ResourceManager
{
#pragma region ST
private:
    ResourceManager();
    ResourceManager(ResourceManager&);
    ResourceManager(ResourceManager&&);
    static ResourceManager* instance;
    ~ResourceManager();
public:
    static ResourceManager* GetInstance();
    static void DestroyInstance();
#pragma endregion
private:
    sf::Texture** vect = nullptr;
    static int count;
    sf::Texture* missingTexture = nullptr;
    sf::Texture* LoadTexture(sf::String path);

public:
    int getRandomNumber(int minValue, int maxValue);
    sf::Texture* GetTexture(Type type);   
    sf::IntRect GetTextureRect(Type type);
};

