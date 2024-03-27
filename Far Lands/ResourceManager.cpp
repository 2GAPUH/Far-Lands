#include "ResourceManager.h"


ResourceManager* ResourceManager::instance = nullptr;
int ResourceManager::textureCount = 0;
int ResourceManager::musicCount = 0;
int ResourceManager::soundCount = 0;

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

#pragma region TEXTURE

    texture = new sf::Texture * [MAX_TEXTURE_COUNT] {nullptr};

    texture[(int)Type::GRASS] = LoadTexture("grass.png");

    texture[(int)Type::PLAYER] = LoadTexture("player.png");

    texture[(int)Type::PLAYER2] = LoadTexture("player2.png");

    texture[(int)Type::ARROW] = LoadTexture("arrow.png");

    texture[(int)Type::CHICKEN] = LoadTexture("chicken.png");

    texture[(int)Type::CHICKEN_MEAT_RAW] = LoadTexture("chicken_meat_raw.png");

    texture[(int)Type::CHICKEN_MEAT_COOKED] = LoadTexture("chicken_meat_cooked.png");

    texture[(int)Type::EGG] = LoadTexture("egg.png");

    texture[(int)Type::INTERFACE] = LoadTexture("interface.png");

    texture[(int)Type::BOW] = LoadTexture("bow.png");

    texture[(int)Type::BERRY_BUSH] = LoadTexture("berry_bush.png");

    texture[(int)Type::INVISIBLE_WALL] = LoadTexture("invisible_wall.png");

    texture[(int)Type::WATER] = LoadTexture("water.png");

    texture[(int)Type::FARMER_PLANTED] = LoadTexture("farmerPlanted.png");

    texture[(int)Type::SLEDGE] = LoadTexture("sledge.png");

    texture[(int)Type::HOE] = LoadTexture("hoe.png");

    texture[(int)Type::STATUS_BAR] = LoadTexture("statusBar.png");

    texture[(int)Type::STATUS_BAR_POINT] = LoadTexture("statusBarPoint.png");

    texture[(int)Type::LOG] = LoadTexture("log.png");

    texture[(int)Type::STUMP] = LoadTexture("stump.png");

    texture[(int)Type::STONE] = LoadTexture("stone.png");

    texture[(int)Type::CAMPFIRE] = LoadTexture("campfire.png");
#pragma endregion

#pragma region MUSIC
    music = new sf::Music * [MAX_MUSIC_COUNT] {nullptr};

    music[(int)MusicList::SPRING_DAY] = LoadMusic("spring_day.wav");

#pragma endregion

#pragma region SOUND
    sound = new sf::SoundBuffer * [MAX_SOUND_COUNT] {nullptr};

    sound[(int)SoundList::CAMPFIRE_ADD_FUEL] = LoadSound("campfire_add_fuel.wav");

    sound[(int)SoundList::DEATH] = LoadSound("death.wav");

    sound[(int)SoundList::EAT] = LoadSound("eat.wav");

    sound[(int)SoundList::HARVEST] = LoadSound("harvest.wav");

    sound[(int)SoundList::HOE_HIT] = LoadSound("hoe_hit.wav");

    sound[(int)SoundList::CHICKEN_DEATH] = LoadSound("chicken_death.wav");

    sound[(int)SoundList::PLANT_BREAK] = LoadSound("plant_break.wav");

    sound[(int)SoundList::SLEDGE_HEAT] = LoadSound("sledge_heat.wav");

    sound[(int)SoundList::STEP] = LoadSound("step.wav");

    sound[(int)SoundList::STONE_BREAK] = LoadSound("stone_break.wav");

    sound[(int)SoundList::WOOD_BREAK] = LoadSound("wood_break.wav");

    sound[(int)SoundList::BOW] = LoadSound("bow.wav");

    sound[(int)SoundList::ADD_FUEL] = LoadSound("add_fuel.wav");

    sound[(int)SoundList::COOKED] = LoadSound("cooked.wav");

    sound[(int)SoundList::EATING] = LoadSound("eating.wav");
#pragma endregion


    for (int i = 0; i < 10; i++)
        soundArray[i].setVolume(30.);
}

ResourceManager::~ResourceManager()
{
    for (int i = 0; i < textureCount; i++)
        if (texture[i] != missingTexture)
            delete texture[i];
    delete texture;
    
    if(missingTexture != nullptr)
    {
        delete missingTexture;
        missingTexture = nullptr;
    }

    

    for (int i = 0; i < musicCount; i++)
        if (music[i] != nullptr)
        {
            music[i]->stop();
            delete music[i];
        }
    delete music;

    for (int i = 0; i < soundCount; i++)
        if (sound[i] != nullptr)
        {
            delete sound[i];
        }
    delete sound;

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
    return texture[(int)type];
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

sf::Music* ResourceManager::GetMusic(MusicList type)
{
    return music[(int)type];
}

void ResourceManager::PlaySound(SoundList type)
{
    for(int i = 0; i < 10; i++)
        if (!(soundArray[i].getStatus() == sf::Sound::Playing))
        {
            soundArray[i].setBuffer(*(sound[(int)type]));
            soundArray[i].play();
            break;
        }
}

void ResourceManager::StopMusic(MusicList type)
{
    music[(int)type]->stop();
}

sf::Texture* ResourceManager::LoadTexture(sf::String path)
{
    path = "Textures\\" + path;
    sf::Texture* tmp = new sf::Texture;
    if (!tmp->loadFromFile(path))
        return missingTexture;
    textureCount++;
    return tmp;
}

sf::SoundBuffer* ResourceManager::LoadSound(sf::String path)
{
    path = "Sound\\" + path;
    sf::SoundBuffer* tmp = new sf::SoundBuffer;
    if (!tmp->loadFromFile(path))
        return tmp;
    soundCount++;
    return tmp;
}

sf::Music* ResourceManager::LoadMusic(sf::String path)
{
    path = "Music\\" + path;
    sf::Music* tmp = new sf::Music;
    if (!tmp->openFromFile(path))
        return tmp;
    musicCount++;
    return tmp;
}


