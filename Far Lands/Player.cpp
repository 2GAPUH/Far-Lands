#include "Player.h"

Player::Player()
{
	stats = new Stats(EntityType::PLAYER);
	ResourceManager::GetInstance()->GetTexture(TextureType::PLAYER);
	//rect.setTexture();
}

Player::~Player()
{
	delete stats;
	stats = nullptr;
}

void Player::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
}
