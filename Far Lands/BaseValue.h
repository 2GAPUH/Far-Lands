#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <random>
#define WIN_SIZE sf::Vector2f{1280, 720}

enum class Type {EMPTY, PLAYER, GRASS, WALL, ARROW, CHICKEN, EGG, CHICKEN_MEAT_RAW, STORAGE, HOT_BAR, 
	CUR_ELEM, BOW, OBJECTS, BERRY_BUSH};

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
#define MAP_SIZE sf::Vector2f{50, 50}

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
#define EQUIP_DISTANCE 30
#define ITEM_IN_WORLD_SIZE sf::Vector2f{32, 32}

#pragma region PLAYER
#define PLAYER_HP 100
#define PLAYER_DMG 10
#define PLAYER_DEFENSE 5
#define PLAYER_SPEED 10
#define PLAYER_MONEY 100
#define PLAYER_LUCKY 0.2
#define PLAYER_COLLISION 1
#define BASE_MAGNET_DISTANCE 200
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
