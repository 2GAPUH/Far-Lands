#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;
int ResourceManager::count = 0;


ResourceManager::ResourceManager()
{
    missingTexture = new sf::Texture;
    missingTexture->loadFromFile(MISSING_TEXTURE_PATH);

    arr = new sf::Texture * [MAX_TEXTURE_COUNT] {nullptr};

    arr[(int)TextureType::GRASS] = LoadTexture("grass.png");
    arr[(int)TextureType::PLAYER] = LoadTexture("player.png");
}

ResourceManager::~ResourceManager()
{
    for (int i = 0; i < count; i++)
        if (arr[i] != missingTexture)
            delete arr[i];
    delete arr;
    
    if(missingTexture != nullptr)
    {
        delete missingTexture;
        missingTexture = nullptr;
    }
}

ResourceManager* ResourceManager::GetInstance()
{
    if (instance == nullptr)
        instance = new ResourceManager();
    return instance;    
}

void ResourceManager::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

sf::Texture* ResourceManager::GetTexture(TextureType type)
{
    return arr[(int)type];
}

sf::Texture* ResourceManager::LoadTexture(sf::String path)
{
    path = "Textures\\" + path;
    sf::Texture* tmp = new sf::Texture;
    if (tmp->loadFromFile(path))
        return missingTexture;
    count++;
    return tmp;
}
