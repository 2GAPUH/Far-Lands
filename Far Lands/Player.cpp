#include "Player.h"
#include "ResourceManager.h"
Player* Player::instance = nullptr;
#include "World.h"

Player::Player()
{
	stats = new Stats(EnemyType::PLAYER);
	rect.setPosition({ WIN_SIZE.x/2 - HERO_SIZE.x /2, WIN_SIZE.y / 2 - HERO_SIZE.y / 2 });
	rect.setSize(HERO_SIZE);
	rect.setFillColor(sf::Color(255, 255, 255));
	animation = new Animation(ResourceManager::GetInstance()->GetTexture(Type::PLAYER));
	spawnTile = { 24, 24 };
	inventory = new Inventory();
	inventory->PutItemAuto(ItemType::CHICKEN_MEAT_RAW, 3);
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
	sf::Vector2f mouseWorldClick = GetCenter() + mousePos - WIN_SIZE * 0.5f;
	sf::Vector2i mouseTileClick = world->GetTilePos(mouseWorldClick);
	sf::Vector2i playerTilePos = world->GetTilePos(GetCenter());
	sf::Vector2i tmp = playerTilePos - mouseTileClick;

	if (tmp.x <= stats->touchDistance && tmp.x >= -stats->touchDistance && tmp.y <= stats->touchDistance && tmp.y >= -stats->touchDistance)
		switch (inventory->GetCurType())
		{
		case ItemType::BERRY_BUSH:
			inventory->ReduceCurElem();
			world->SetObject(ObjectType::BERRY_BUSH, mouseTileClick);
			break;
		}
	
	switch (inventory->GetCurType())
	{
	case ItemType::BOW:
		entityManager->Create(ProjectileType::ARROW, GetCenter(), mouseWorldClick);
		break;
	}
}

void Player::Draw(sf::RenderWindow* win)
{
	animation->Draw(viewDerection, win, rect.getPosition());
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

void Player::CheckViewDerection(sf::Vector2f shift)
{
	if (shift == sf::Vector2f{ 0, 0 })
	{
		viewDerection = StateType::IDLE;
		return;
	}
	if (shift.x > 0)
		viewDerection = StateType::RIGHT;
	else if (shift.x < 0)
		viewDerection = StateType::LEFT;
	else if (shift.y > 0)
		viewDerection = StateType::DOWN;
	else if (shift.y < 0)
		viewDerection = StateType::TOP;

}

sf::Vector2f Player::GetCenter()
{
	return rect.getPosition() + 0.5f * rect.getSize();
}

sf::FloatRect Player::GetPosition()
{
	return rect.getGlobalBounds();
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

void Player::Update(sf::RenderWindow* win)
{
	inventory->Update(win);
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

