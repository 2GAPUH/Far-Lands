#pragma once
#include <SFML\Graphics.hpp>
#define WIN_HEIGHT 720
#define WIN_WIDTH 1280

enum class EntityType { PLAYER };

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