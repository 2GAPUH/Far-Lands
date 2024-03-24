#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;
int ResourceManager::count = 0;

const sf::IntRect TextureRect::STORAGE = { 0, 0, 161, 85 };
const sf::IntRect TextureRect::HOT_BAR = { 0, 96, 161, 28 };
const sf::IntRect TextureRect::CUR_ELEM = { 176, 0, 16, 16 };


ResourceManager::ResourceManager()
{
    missingTexture = new sf::Texture;
    missingTexture->loadFromFile(MISSING_TEXTURE_PATH);

    font = new sf::Font;    
    if (!font->loadFromFile("BrassMono.ttf")) // Загрузка шрифта
    {
        std::cout << "Error text load!";
    }

    vect = new sf::Texture * [MAX_TEXTURE_COUNT] {nullptr};

    vect[(int)Type::GRASS] = LoadTexture("grass.png");

    vect[(int)Type::PLAYER] = LoadTexture("player.png");

    vect[(int)Type::WALL] = LoadTexture("wall.png");

    vect[(int)Type::ARROW] = LoadTexture("arrow.png");

    vect[(int)Type::CHICKEN] = LoadTexture("chicken.png");

    vect[(int)Type::CHICKEN_MEAT_RAW] = LoadTexture("chicken_meat_raw.png");

    vect[(int)Type::EGG] = LoadTexture("egg.png");

    vect[(int)Type::INTERFACE] = LoadTexture("interface.png");

    vect[(int)Type::BOW] = LoadTexture("bow.png");

    vect[(int)Type::BERRY_BUSH] = LoadTexture("berry_bush.png");

    vect[(int)Type::OBJECTS] = LoadTexture("objects.png");

    vect[(int)Type::INVISIBLE_WALL] = LoadTexture("invisible_wall.png");

    vect[(int)Type::WATER] = LoadTexture("water.png");

    vect[(int)Type::FARMER_PLANTED] = LoadTexture("FarmerPlanted.png");

    vect[(int)Type::FARMER_PLANTED] = LoadTexture("FarmerPlanted.png");

    vect[(int)Type::AXE] = LoadTexture("Axe.png");

    vect[(int)Type::HOE] = LoadTexture("Hoe.png");

    vect[(int)Type::BERRYS] = LoadTexture("Berrys.png");
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

    delete font;
    font = nullptr;
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
        rect.left = RandomNumber::GetRandomNumber(0, 11) * TEXTURE_SIZE;
        break;
    case Type::WATER:
        rect.left = RandomNumber::GetRandomNumber(0, 3) * TEXTURE_SIZE;
        break;
    case Type::OBJECTS:
        rect.left = RandomNumber::GetRandomNumber(0, 5) * TEXTURE_SIZE;
        break;
    case Type::BERRY_BUSH:
        rect.left = 0;
        break;
    case Type::BOW:
        rect = { 0, 0, 64, 64 };
        break;
    }
    return rect;
}

sf::IntRect ResourceManager::GetTextureRect(Type type, sf::Vector2i pos)
{
    return sf::IntRect{ pos.x * TEXTURE_SIZE, pos.y * TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE };
}

sf::Font* ResourceManager::GetFont()
{
    return font;
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


