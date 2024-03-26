#include "PlayerStats.h"
#include "ResourceManager.h"

PlayerStats::PlayerStats() : Stats(EnemyType::PLAYER)
{
	statusBar.setSize(sf::Vector2f{ 192, 144 });
	statusBar.setTexture(ResourceManager::GetInstance()->GetTexture(Type::STATUS_BAR));

	point.setSize(sf::Vector2f{ 12, 12 });
	point.setTexture(ResourceManager::GetInstance()->GetTexture(Type::STATUS_BAR_POINT));

	starve = 10;
	energy = 10;
}

PlayerStats::~PlayerStats()
{
}

void PlayerStats::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	statusBar.setPosition(pos);

	win->draw(statusBar);
	
	point.setTextureRect(sf::IntRect{ 0, 0, 4, 4 });
	for (int i = 0; i < HP; i++)
	{
		point.setPosition(sf::Vector2f{ 36.f + 15 * i, 24 } + pos);
		win->draw(point);
	}

	point.setTextureRect(sf::IntRect{ 4, 0, 4, 4 });
	for (int i = 0; i < energy; i++)
	{
		point.setPosition(sf::Vector2f{ 36.f + 15 * i, 72 } + pos);
		win->draw(point);
	}

	point.setTextureRect(sf::IntRect{ 8, 0, 4, 4 });
	for (int i = 0; i < starve; i++)
	{
		point.setPosition(sf::Vector2f{ 36.f + 15 * i, 120 } + pos);
		win->draw(point);
	}
}

void PlayerStats::Update()
{

}
