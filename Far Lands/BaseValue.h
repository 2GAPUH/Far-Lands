#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <random>
#include <unordered_map>
#define WIN_SIZE sf::Vector2f{1280, 720}
#define ROOT_CONST 1.414213562373
enum class StateType { LEFT, RIGHT, DOWN, TOP, IDLE };

#define BASE_FRAME_TIME 50
#define BASE_FRAME_COUNT 4
#define BASE_FRAME_SIZE sf::Vector2f{16, 16}


enum class Type {EMPTY, PLAYER, GRASS, WALL, ARROW, CHICKEN, EGG, CHICKEN_MEAT_RAW, INTERFACE, BOW, OBJECTS, BERRY_BUSH, INVISIBLE_WALL};

enum class ObjectType {
    OBJECTS = static_cast<int>(Type::OBJECTS),
    BERRY_BUSH = static_cast<int>(Type::BERRY_BUSH),
    WALL = static_cast<int>(Type::WALL),
    INVISIBLE_WALL = static_cast<int>(Type::INVISIBLE_WALL)
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
    BERRY_BUSH = static_cast<int>(Type::BERRY_BUSH)
};

class TypeConverter {
public:
    static Type Convert(ItemType itemType) {
        static const std::unordered_map<ItemType, Type> typeMap = {
            {ItemType::EGG, Type::EGG},
            {ItemType::CHICKEN_MEAT_RAW, Type::CHICKEN_MEAT_RAW},
            {ItemType::BOW, Type::BOW},
            {ItemType::EMPTY, Type::EMPTY},
            {ItemType::BERRY_BUSH, Type::BERRY_BUSH}
            
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
            {ObjectType::WALL, Type::WALL},
            {ObjectType::BERRY_BUSH, Type::BERRY_BUSH},
            {ObjectType::INVISIBLE_WALL, Type::INVISIBLE_WALL},
            {ObjectType::OBJECTS, Type::OBJECTS}
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
        static std::random_device rd; // ������������� ���������� ��������� �����
        static std::mt19937 gen(rd()); // ���������� ��������� Mersenne Twister
        std::uniform_int_distribution<> distrib(minValue, maxValue); // ������ ����������� ������������� � �������� ���������

        return distrib(gen); // ���������� ��������� �����
    }
};

struct MyTexture
{
	sf::Vector2i frameCount = { 0, 0 };
	sf::Texture* texture;
};

#define MISSING_TEXTURE_PATH "Textures\\missingTexture.png"

#define MAX_TEXTURE_COUNT 100

#define BASE_GAZE_DERECTION 0
#define TEXTURE_SIZE 16

#define HERO_SIZE sf::Vector2f{48, 48}
#define CHICKEN_SIZE sf::Vector2f{48, 48}
#define TILE_SIZE sf::Vector2f{48, 48}

#define FRAME_SIZE 16

#define FRAME_LIMIT 30

#define ARROW_SPEED 15
#define ARROW_SIZE sf::Vector2f{41, 5}
#define ARROW_DMG 10

#define ITEM_PICK_UP_SPEED 15

#define STORAGE_SIZE sf::Vector2i{8, 4}
#define STORAGE_SIZE_OPEN sf::Vector2f{644, 340}
#define HOT_BAR_SIZE sf::Vector2f{644, 112}
#define STORAGE_CELL sf::Vector2f{64, 64}
#define STACK_MAX_COUNT 2
#define CUR_ELEM_TEXTURE_SIZE sf::Vector2f{64, 64}

#pragma region PLAYER
#define PLAYER_HP 100
#define PLAYER_DMG 10
#define PLAYER_DEFENSE 5
#define PLAYER_SPEED 10
#define PLAYER_MONEY 100
#define PLAYER_LUCKY 0.2
#define PLAYER_COLLISION 1
#define BASE_MAGNET_DISTANCE 200
#define TOUCH_DISTANCE 3
#pragma endregion

#pragma region CHICKEN
#define CHICKEN_HP 30
#define CHICKEN_DMG 10
#define CHICKEN_DEFENSE 1
#define CHICKEN_SPEED 5
#define CHICKEN_MONEY 0
#define CHICKEN_LUCKY 0
#define CHICKEN_COLLISION 1
#pragma endregion
