#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;
int ResourceManager::count = 0;

int getRandomNumber(int minValue, int maxValue)
{
    static std::random_device rd; // »нициализаци€ генератора случайных чисел
    static std::mt19937 gen(rd()); // »спользуем генератор Mersenne Twister
    std::uniform_int_distribution<> distrib(minValue, maxValue); // «адаем равномерное распределение в заданном диапазоне

    return distrib(gen); // ¬озвращаем случайное число
}


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

sf::IntRect ResourceManager::GetTextureRect(TextureType type)
{
    sf::IntRect rect = { 0, 0, TEXTURE_SIZE, TEXTURE_SIZE };
    switch (type)
    {
    case TextureType::GRASS:
        rect.left = getRandomNumber(0, 11) * TEXTURE_SIZE;
    }
    return rect;
}

sf::Texture* ResourceManager::LoadTexture(sf::String path)
{
    path = "Textures\\" + path;
    sf::Texture* tmp = new sf::Texture;
    if (!tmp->loadFromFile(path))
        return missingTexture;
    count++;
    return tmp;
}
