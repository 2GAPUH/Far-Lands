#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;
int ResourceManager::count = 0;

ResourceManager::ResourceManager()
{
    missingTexture = new sf::Texture;
    missingTexture->loadFromFile(MISSING_TEXTURE_PATH);

    font = new sf::Font;    
    if (!font->loadFromFile("BrassMono.ttf")) // �������� ������
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

    vect[(int)Type::STORAGE] = LoadTexture("storage.png");

    vect[(int)Type::HOT_BAR] = LoadTexture("hot_bar.png");

    vect[(int)Type::CUR_ELEM] = LoadTexture("cur_elem.png");

    vect[(int)Type::BOW] = LoadTexture("bow.png");

    vect[(int)Type::BERRY_BUSH] = LoadTexture("berry_bush.png");

    vect[(int)Type::OBJECTS] = LoadTexture("objects.png");
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
        rect.left = getRandomNumber(0, 11) * TEXTURE_SIZE;
        break;
    case Type::OBJECTS:
        rect.left = getRandomNumber(0, 5) * TEXTURE_SIZE;
        break;
    }
    return rect;
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

int ResourceManager::getRandomNumber(int minValue, int maxValue)
{
    static std::random_device rd; // ������������� ���������� ��������� �����
    static std::mt19937 gen(rd()); // ���������� ��������� Mersenne Twister
    std::uniform_int_distribution<> distrib(minValue, maxValue); // ������ ����������� ������������� � �������� ���������

    return distrib(gen); // ���������� ��������� �����
}
