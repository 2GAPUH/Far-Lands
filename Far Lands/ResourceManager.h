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
    sf::Texture** texture = nullptr;
    sf::Music** music = nullptr;
    sf::SoundBuffer** sound = nullptr;
    static int textureCount;
    static int musicCount;
    static int soundCount;
    sf::Texture* missingTexture = nullptr;
    sf::Texture* LoadTexture(sf::String path);
    sf::SoundBuffer* LoadSound(sf::String path);
    sf::Music* LoadMusic(sf::String path);
    sf::Font* font = nullptr;
    sf::Sound soundArray[10];

public:
    sf::Texture* GetTexture(Type type);
    sf::IntRect GetTextureRect(Type type);
    sf::IntRect GetTextureRect(Type type, sf::Vector2i pos);

    sf::Font* GetFont();

    sf::Music* GetMusic(MusicList type);

    void PlaySound(SoundList type);
    void StopMusic(MusicList type);
};

class TextureRect
{
public:
    static const sf::IntRect STORAGE;
    static const sf::IntRect HOT_BAR;
    static const sf::IntRect CUR_ELEM;
};

