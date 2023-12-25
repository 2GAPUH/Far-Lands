#include "Player.h"
#include "ResourceManager.h"
Player* Player::instance = nullptr;

Player::Player()
{
	stats = new Stats(Type::PLAYER);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(Type::PLAYER));
	rect.setPosition({ WIN_SIZE.x/2 - HERO_SIZE.x /2, WIN_SIZE.y / 2 - HERO_SIZE.y / 2 });
	rect.setSize(HERO_SIZE);
	rect.setFillColor(sf::Color(255, 255, 255));
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

float Player::GetSpeed()
{
	return stats->speed;
}

void Player::Move(sf::Vector2f shift)
{
	rect.move(shift);
}

sf::Vector2f Player::GetCenter()
{
	return { rect.getPosition().x + rect.getSize().x / 2, rect.getPosition().y + rect.getSize().y / 2 };
}

sf::FloatRect Player::GetPosition()
{
	return rect.getGlobalBounds();
}

sf::Vector2i Player::GetTilePosition()
{
	UpdateTilePosition();
	return tilePos;
}

float Player::GetMagnetDistance()
{
	return stats->magnetDistance;
}



Player* Player::GetInstance()
{
    if (instance == nullptr)
        instance = new Player();
    return instance;
}

void Player::DestroyInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

void Player::UpdateTilePosition()
{
	tilePos.x = (rect.getPosition().x + rect.getSize().x / 2) / TILE_SIZE.x;
	tilePos.y = (rect.getPosition().y + rect.getSize().y / 2) / TILE_SIZE.y;
}
