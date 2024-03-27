#include "PlayerStats.h"
#include "ResourceManager.h"
#include "GameCore.h"

void PlayerStats::Starve()
{
	if (starveClock.getElapsedTime().asSeconds() > STARVE_TIME)
	{
		if (starve > 0)
			starve--;
		
		else
			Damage(1);
		
		starveClock.restart();
	}
}

void PlayerStats::Tired()
{
	if (energyClock.getElapsedTime().asSeconds() > ENERGY_TIME && restClock.getElapsedTime().asSeconds() > REST_TIME + 1)
	{
		if (energy > 0)
			energy--;
		
		else
			Damage(1);
		
		energyClock.restart();
	}
}

PlayerStats::PlayerStats() : Stats(EnemyType::PLAYER)
{
	statusBar.setSize(sf::Vector2f{ 192, 144 });
	statusBar.setTexture(ResourceManager::GetInstance()->GetTexture(Type::STATUS_BAR));

	point.setSize(sf::Vector2f{ 12, 12 });
	point.setTexture(ResourceManager::GetInstance()->GetTexture(Type::STATUS_BAR_POINT));

	starve = STARVE_MAX_COUNT;
	energy = ENERGY_MAX_COUNT;
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
	Starve();
	Tired();
}

void PlayerStats::Damage(int i)
{
	HP -= i;

	if (HP <= 0)
	{
		GameCore::GetInstance()->EndGame();
		return;
	}
}

void PlayerStats::RestoreEnergy(int i)
{
	energy += i;
	if (energy > ENERGY_MAX_COUNT)
		energy = 10;
}

void PlayerStats::Rest()
{
	if (restClock.getElapsedTime().asSeconds() > REST_TIME)
	{
		restClock.restart();
		RestoreEnergy(1);
	}
}
