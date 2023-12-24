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

    vect = new sf::Texture * [MAX_TEXTURE_COUNT] {nullptr};

    vect[(int)Type::GRASS] = LoadTexture("grass.png");

    vect[(int)Type::PLAYER] = LoadTexture("player.png");

    vect[(int)Type::WALL] = LoadTexture("wall.png");

    vect[(int)Type::ARROW] = LoadTexture("arrow.png");

    vect[(int)Type::CHICKEN] = LoadTexture("chicken.png");

    vect[(int)Type::APPLE] = LoadTexture("apple.png");
}

ResourceManager::~ResourceManager()
{
    for (int i = 0; i < count; i++)
        if (vect[i] != missingTexture)
            delete vect[i];
    delete vect;
    
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

sf::Texture* ResourceManager::GetTexture(Type type)
{
    return vect[(int)type];
}

sf::IntRect ResourceManager::GetTextureRect(Type type)
{
    sf::IntRect rect = { 0, 0, TEXTURE_SIZE, TEXTURE_SIZE };
    switch (type)
    {
    case Type::GRASS:
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
