#include "Player.h"
#include "ResourceManager.h"
Player* Player::instance = nullptr;
#include "World.h"

Player::Player()
{
	stats = new Stats(EnemyType::PLAYER);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(Type::PLAYER));
	rect.setPosition({ WIN_SIZE.x/2 - HERO_SIZE.x /2, WIN_SIZE.y / 2 - HERO_SIZE.y / 2 });
	rect.setSize(HERO_SIZE);
	rect.setFillColor(sf::Color(255, 255, 255));
	spawnTile = { 24, 24 };
	inventory = new Inventory();
	inventory->PutItemAuto(ItemType::CHICKEN_MEAT_RAW, 21);
	entityManager = EntityManager::GetInstance();
	inventory->PutItemAuto(ItemType::BOW, 1);
	inventory->PutItemAuto(ItemType::BERRY_BUSH, 6);
	world = World::GetInstance();
}

Player::~Player()
{
	delete stats;
	stats = nullptr;
	delete inventory;
	inventory = nullptr;
}

void Player::Use(sf::Vector2f mousePos)
{
	switch (inventory->GetCurType())
	{
	case ItemType::BOW:
		entityManager->Create(ProjectileType::ARROW, GetCenter(), GetCenter() - WIN_SIZE / 2.f + mousePos);
		break;
	case ItemType::BERRY_BUSH:
		inventory->ReduceCurElem();
		world->SetObject(ObjectType::BERRY_BUSH, GetTilePosition());
		break;
		
	}
}

void Player::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
	inventory->Draw(win, GetCenter() - WIN_SIZE / 2.f);
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

int Player::PickUpItem(ItemType type, int count)
{
	return inventory->PutItemAuto(type, count);
}

void Player::EditCurLine()
{
	inventory->EditCurLine();
}

void Player::EditCurElem(int i)
{
	inventory->EditCurElem(i);
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
