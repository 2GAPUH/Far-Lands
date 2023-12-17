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
    sf::Texture** arr = nullptr;
    static int count;
    sf::Texture* missingTexture = nullptr;
    sf::Texture* LoadTexture(sf::String path);


public:
    sf::Texture* GetTexture(TextureType type);   
    sf::IntRect GetTextureRect(TextureType type);
};

