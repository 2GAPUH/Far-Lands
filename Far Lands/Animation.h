#pragma once
#include "BaseValue.h"

class Animation
{
private:
	int frameTime = BASE_FRAME_TIME;
	int frameCount = BASE_FRAME_COUNT;
	sf::Vector2i curFrame = {0, 0};
	FullStateType curState = FullStateType::DOWN;
	sf::Vector2f frameSize = BASE_FRAME_SIZE;
	sf::Sprite sprite;
	sf::Clock clock;

public:
	Animation(sf::Texture* texture, sf::Vector2f frameSize);
	Animation(sf::Texture* texture);
	void Draw(FullStateType state, sf::RenderWindow* win, sf::Vector2f pos);
	void Draw(ShortStateType state, sf::RenderWindow* win, sf::Vector2f pos);
};

