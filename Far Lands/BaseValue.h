#pragma once
#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#define WIN_HEIGHT 720
#define WIN_WIDTH 1280

enum class EntityType { PLAYER };

enum class TileType { GRASS};

enum class TextureType {PLAYER, GRASS };

#define MISSING_TEXTURE_PATH "Textures\\missingTexture.png"

#define MAX_TEXTURE_COUNT 100

#define BASE_GAZE_DERECTION 0

#pragma region PLAYER
#define PLAYER_HP 100
#define PLAYER_DMG 10
#define PLAYER_DEFENSE 5
#define PLAYER_SPEED 1
#define PLAYER_MONEY 100
#define PLAYER_LUCKY 0.2
#define PLAYER_COLLISION 1
#pragma endregion