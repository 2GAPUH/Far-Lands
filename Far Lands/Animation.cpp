#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2f frameSize)
{
	sprite.setTexture(*texture);
	this->frameSize = frameSize;
	sprite.setScale(sf::Vector2f(3., 3.));
}

Animation::Animation(sf::Texture* texture) 
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(3., 3.));
}



void Animation::Draw(StateType state, sf::RenderWindow* win, sf::Vector2f pos)
{
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



