#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2f frameSize, int frameCount, sf::Vector2f scale)
{
	sprite.setTexture(*texture);
	this->frameSize = frameSize;
	this->frameCount = frameCount;
	sprite.setScale(scale);
}

void Animation::Draw(StateType state, sf::RenderWindow* win, sf::Vector2f pos)
{
	static StateType curState = StateType::DOWN;

	sprite.setPosition(pos);
	
	if (curState != state)
	{
		if(state == StateType::IDLE)
			curFrame = { 0, (int)curState};
		else
			curFrame = { 0, (int)state };

		curState = state;
		sf::IntRect tmp = { int(frameSize.x * curFrame.x), int(frameSize.y * curFrame.y), int(frameSize.x), int(frameSize.y) };
		sprite.setTextureRect(tmp);
	}

	win->draw(sprite);

	if(curState != StateType::IDLE)
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

void Animation::Draw(StatusType status, sf::RenderWindow* win, sf::Vector2f pos)
{
	static StatusType curStatus = StatusType::ENABLE;
	sprite.setPosition(pos);

	if (curStatus != status)
	{
		curStatus = status;
		if (curStatus == StatusType::ENABLE)
			curFrame = { 0, 0 };
		else if (curStatus == StatusType::DISABLE)
			curFrame = { 0, 1 };
		clock.restart();
	}

	if (clock.getElapsedTime().asMilliseconds() > frameTime)
	{
		curFrame.x++;
		if (curFrame.x >= frameCount)
			curFrame = { 0, curFrame.y };

		clock.restart();
	}

	
	sf::IntRect tmpRect = { int(curFrame.x * frameSize.x), int(curFrame.y * frameSize.y), int(frameSize.x), int(frameSize.y)};
	sprite.setTextureRect(tmpRect);
	win->draw(sprite);
}



