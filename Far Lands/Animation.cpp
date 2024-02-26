#include "Animation.h"

FullStateType ConvertShortToFull(ShortStateType shortState) {
	switch (shortState) {
	case ShortStateType::LEFT:
		return FullStateType::LEFT;
	case ShortStateType::RIGHT:
		return FullStateType::RIGHT;
	case ShortStateType::IDLE:
		return FullStateType::IDLE;
	}
	// Возвращаем значение по умолчанию
	return FullStateType::IDLE;
}

Animation::Animation(sf::Texture* texture, sf::Vector2f frameSize)
{
	sprite.setTexture(*texture);
	this->frameSize = frameSize;
}

Animation::Animation(sf::Texture* texture) 
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(3., 3.));
}

void Animation::Draw(FullStateType state, sf::RenderWindow* win, sf::Vector2f pos)
{
	sprite.setPosition(pos);
	
	if (curState != state)
	{
		if(state == FullStateType::IDLE)
			curFrame = { 0, (int)curState};
		else
			curFrame = { 0, (int)state };

		curState = state;
		sf::IntRect tmp = { int(frameSize.x * curFrame.x), int(frameSize.y * curFrame.y), int(frameSize.x), int(frameSize.y) };
		sprite.setTextureRect(tmp);
	}

	win->draw(sprite);

	if(curState != FullStateType::IDLE)
		if (clock.getElapsedTime().asMilliseconds() > frameTime)
		{
			curFrame.x++;
			if (curFrame.x >= frameCount)
				curFrame.x = 0;
			sf::IntRect tmp = { int(frameSize.x * curFrame.x), int(frameSize.y * curFrame.y), int(frameSize.x), int(frameSize.y)};
			sprite.setTextureRect(tmp);
			clock.restart();
		}
}

void Animation::Draw(ShortStateType state, sf::RenderWindow* win, sf::Vector2f pos)
{
	Draw(ConvertShortToFull(state), win, pos);
}



