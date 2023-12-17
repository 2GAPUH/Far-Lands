#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <random>
#define WIN_SIZE sf::Vector2f{1280, 720}

enum class EntityType { PLAYER };

enum class TileType { GRASS};

enum class TextureType { PLAYER, GRASS };

struct MyTexture
{
	sf::Vector2i frameCount = { 0, 0 };
	sf::Texture* texture;
};

#define MISSING_TEXTURE_PATH "Textures\\missingTexture.png"

#define MAX_TEXTURE_COUNT 100

#define BASE_GAZE_DERECTION 0
#define TEXTURE_SIZE 16

#define HERO_SIZE sf::Vector2f{32, 32}
#define TILE_SIZE sf::Vector2f{32, 32}
#define MAP_SIZE sf::Vector2f{50, 50}

#define FRAME_SIZE 16

#define FRAME_LIMIT 60

#pragma region PLAYER
#define PLAYER_HP 100
#define PLAYER_DMG 10
#define PLAYER_DEFENSE 5
#define PLAYER_SPEED 3
#define PLAYER_MONEY 100
#define PLAYER_LUCKY 0.2
#define PLAYER_COLLISION 1
#pragma endregion









