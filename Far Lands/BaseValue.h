#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <random>
#define WIN_SIZE sf::Vector2f{1280, 720}

enum class Type { PLAYER, GRASS, WALL, ARROW, CHICKEN, APPLE};

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

#pragma region PLAYER
#define PLAYER_HP 100
#define PLAYER_DMG 10
#define PLAYER_DEFENSE 5
#define PLAYER_SPEED 10
#define PLAYER_MONEY 100
#define PLAYER_LUCKY 0.2
#define PLAYER_COLLISION 1
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









