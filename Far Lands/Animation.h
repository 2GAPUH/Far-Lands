#pragma once
#include "BaseValue.h"

class Animation
{
private:
	int frameTime = BASE_FRAME_TIME;
	int frameCount = BASE_FRAME_COUNT;
	sf::Vector2i curFrame = {0, 0};
	sf::Vector2f frameSize = BASE_FRAME_SIZE;
	sf::Sprite sprite;
	sf::Clock clock;
	StateType curState = StateType::DOWN;
	StatusType curStatus = StatusType::ENABLE;

public:
	Animation(sf::Texture* texture, sf::Vector2f frameSize = { 16, 16 }, int frameCount = 4, sf::Vector2f scale = {3, 3});
	void Draw(StateType state, sf::RenderWindow* win, sf::Vector2f pos);
	void Draw(StatusType state, sf::RenderWindow* win, sf::Vector2f pos);
};
