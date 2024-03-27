#pragma once
#include <SFML\Graphics.hpp>
#include "SFML/Audio.hpp"
#include <iostream>
#include <random>
#include <unordered_map>
#define WIN_SIZE sf::Vector2f{1280, 720}
#define ROOT_CONST 1.414213562373
enum class StateType { LEFT, RIGHT, DOWN, TOP, IDLE };
enum class StatusType {ENABLE, DISABLE};
enum class CollisionInfo {FALSE, TRUE, OUT_WORLD};

#define BASE_FRAME_TIME 50
#define BASE_FRAME_COUNT 4
#define BASE_FRAME_SIZE sf::Vector2f{16, 16}


enum class Type { EMPTY, PLAYER, GRASS, ARROW, CHICKEN, EGG, CHICKEN_MEAT_RAW, INTERFACE, BOW, BERRY_BUSH, INVISIBLE_WALL, WATER, FARMER_PLANTED, HOE, SLEDGE, STATUS_BAR, 
    STATUS_BAR_POINT, STONE, LOG, CAMPFIRE, STUMP, PLAYER2 };

enum class SoundList {SLEDGE_HEAT, CAMPFIRE_ADD_FUEL, DEATH, EAT, HARVEST, HOE_HIT, CHICKEN_DEATH, PLANT_BREAK, STEP, STONE_BREAK, WOOD_BREAK, BOW};

enum class MusicList { SPRING_DAY };

enum class ObjectType {
    BERRY_BUSH = static_cast<int>(Type::BERRY_BUSH),
    INVISIBLE_WALL = static_cast<int>(Type::INVISIBLE_WALL),
    FARMER_PLANTED = static_cast<int>(Type::FARMER_PLANTED),
    EMPTY = static_cast<int>(Type::EMPTY),
    STONE = static_cast<int>(Type::STONE),
    LOG = static_cast<int>(Type::LOG),
    CAMPFIRE = static_cast<int>(Type::CAMPFIRE),
    STUMP = static_cast<int>(Type::STUMP)
};

enum class EnemyType {
    CHICKEN = static_cast<int>(Type::CHICKEN),
    PLAYER = static_cast<int>(Type::PLAYER)
};

enum class ProjectileType {
	ARROW = static_cast<int>(Type::ARROW)
};

enum class ItemType {
    EGG = static_cast<int>(Type::EGG),
    CHICKEN_MEAT_RAW = static_cast<int>(Type::CHICKEN_MEAT_RAW),
    BOW = static_cast<int>(Type::BOW),
    EMPTY = static_cast<int>(Type::EMPTY),
    HOE = static_cast<int>(Type::HOE),
    AXE = static_cast<int>(Type::SLEDGE),
    BERRYS = static_cast<int>(Type::BERRY_BUSH),
    SMALL_LOG = static_cast<int>(Type::STUMP),
    BIG_LOG = static_cast<int>(Type::LOG),
    STONE = static_cast<int>(Type::STONE)
};

class TypeConverter {
public:
    static Type Convert(ItemType itemType) {
        static const std::unordered_map<ItemType, Type> typeMap = {
            {ItemType::EGG, Type::EGG},
            {ItemType::CHICKEN_MEAT_RAW, Type::CHICKEN_MEAT_RAW},
            {ItemType::BOW, Type::BOW},
            {ItemType::EMPTY, Type::EMPTY},
            {ItemType::BERRYS, Type::BERRY_BUSH},
            {ItemType::HOE, Type::HOE},
            {ItemType::AXE, Type::SLEDGE},
            {ItemType::SMALL_LOG, Type::STUMP},
            {ItemType::BIG_LOG, Type::LOG},
            {ItemType::STONE, Type::STONE}
        };

        auto it = typeMap.find(itemType);
        return (it != typeMap.end()) ? it->second : Type::EMPTY;
    }
    static Type Convert(EnemyType itemType) {
        static const std::unordered_map<EnemyType, Type> typeMap = {
            {EnemyType::CHICKEN, Type::CHICKEN},
            {EnemyType::PLAYER, Type::PLAYER}
        };

        auto it = typeMap.find(itemType);
        return (it != typeMap.end()) ? it->second : Type::EMPTY;
    }
    static Type Convert(ProjectileType itemType) {
        static const std::unordered_map<ProjectileType, Type> typeMap = {
            {ProjectileType::ARROW, Type::ARROW}
        };

        auto it = typeMap.find(itemType);
        return (it != typeMap.end()) ? it->second : Type::EMPTY;
    }
    static Type Convert(ObjectType itemType) {
        static const std::unordered_map<ObjectType, Type> typeMap = {
            {ObjectType::BERRY_BUSH, Type::BERRY_BUSH},
            {ObjectType::INVISIBLE_WALL, Type::INVISIBLE_WALL},
            {ObjectType::FARMER_PLANTED, Type::FARMER_PLANTED},
            {ObjectType::EMPTY, Type::EMPTY},
            {ObjectType::STONE, Type::STONE},
            {ObjectType::LOG, Type::LOG},
            {ObjectType::CAMPFIRE, Type::CAMPFIRE},
            {ObjectType::STUMP, Type::STUMP}
        };

        auto it = typeMap.find(itemType);
        return (it != typeMap.end()) ? it->second : Type::EMPTY;
    }
};

class RandomNumber
{
public:
    static int GetRandomNumber(int minValue, int maxValue)
    {
        static std::random_device rd; // Инициализация генератора случайных чисел
        static std::mt19937 gen(rd()); // Используем генератор Mersenne Twister
        std::uniform_int_distribution<> distrib(minValue, maxValue); // Задаем равномерное распределение в заданном диапазоне

        return distrib(gen); // Возвращаем случайное число
    }
};

struct MyTexture
{
	sf::Vector2i frameCount = { 0, 0 };
	sf::Texture* texture;
};

#define MISSING_TEXTURE_PATH "Textures\\missingTexture.png"

#define MAX_TEXTURE_COUNT 100
#define MAX_MUSIC_COUNT 10
#define MAX_SOUND_COUNT 100

#define BASE_GAZE_DERECTION 0
#define TEXTURE_SIZE 16

#define HERO_SIZE sf::Vector2f{48, 48}
#define CHICKEN_SIZE sf::Vector2f{48, 48}
#define TILE_SIZE sf::Vector2f{48, 48}

#define FRAME_SIZE 16

#define FRAME_LIMIT 30

#define ARROW_SPEED 15
#define ARROW_SIZE sf::Vector2f{41, 5}
#define ARROW_DMG 1

#define ITEM_PICK_UP_SPEED 15

#define STORAGE_SIZE sf::Vector2i{8, 4}
#define STORAGE_SIZE_OPEN sf::Vector2f{644, 340}
#define HOT_BAR_SIZE sf::Vector2f{644, 112}
#define STORAGE_CELL sf::Vector2f{64, 64}
#define STACK_MAX_COUNT 4
#define CUR_ELEM_TEXTURE_SIZE sf::Vector2f{64, 64}

#pragma region PLAYER
#define PLAYER_HP 10
#define PLAYER_DMG 1
#define PLAYER_SPEED 10
#define PLAYER_COLLISION 1
#define BASE_MAGNET_DISTANCE 200
#define TOUCH_DISTANCE 3
#pragma endregion

#pragma region CHICKEN
#define CHICKEN_HP 3
#define CHICKEN_DMG 1
#define CHICKEN_SPEED 5
#define CHICKEN_COLLISION 1
#pragma endregion


#define STARVE_TIME  10
#define ENERGY_TIME 15

#define ALIVE true
#define DEAD false

/*
+добавить возможность ломать объекты с дропом
добавить хищника, который охотится на сущности
добавить взаимодействие с пашней
+добавить уничтожение кустика, с сбором ягод
возможность садить ягоды, которые вырастают в кустик
добавить систему голода и поглащения еды
усталость, которая восполняется костром, который создается и восполняется поленьями

+переделать систему классов
*/