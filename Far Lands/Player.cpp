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
	spawnTile = { 24, 24 };
	inventory = new Storage();
	inventory->PutItemAuto(Type::CHICKEN_MEAT_RAW, 21);
	inventory->PutItemAuto(Type::CHICKEN_MEAT_RAW, 2);
}

Player::~Player()
{
	delete stats;
	stats = nullptr;
	delete inventory;
	inventory = nullptr;
}



void Player::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
	inventory->Draw(win);
}

float Player::GetSpeed()
{
	return stats->speed;
}

void Player::Move(sf::Vector2f shift)
{
	rect.move(shift);
	inventory->Move(shift);
}

sf::Vector2f Player::GetCenter()
{
	return rect.getPosition() + 0.5f * rect.getSize();
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

void Player::Respawn()
{
	sf::Vector2f tmp = spawnTile * TILE_SIZE.x;
	Move(tmp - rect.getPosition());
}

void Player::OpenInventory()
{
	inventory->Open();
}

int Player::PickUpItem(Type type, int count)
{
	return inventory->PutItemAuto(type, count);
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
	if (tilePos.x <= 1 || tilePos.x >= MAP_SIZE.x - 2 || tilePos.y <= 1 || tilePos.y >= MAP_SIZE.y - 2)
		Respawn();
}
