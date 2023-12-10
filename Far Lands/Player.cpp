#include "Player.h"
#include "ResourceManager.h"

Player::Player()
{
	stats = new Stats(EntityType::PLAYER);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(TextureType::PLAYER));
	rect.setPosition({ WIN_SIZE.x/2 - HERO_SIZE.x /2, WIN_SIZE.y / 2 - HERO_SIZE.y / 2 });
	rect.setSize(HERO_SIZE);
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
