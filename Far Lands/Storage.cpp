#include "Storage.h"
#include "ResourceManager.h"

Storage::Storage()
{
	storage = new ItemInStorage**[STORAGE_SIZE.x];

	for (int i = 0; i < STORAGE_SIZE.x; i++)
		storage[i] = new ItemInStorage*[STORAGE_SIZE.y];

	for (int i = 0; i < STORAGE_SIZE.x; i++)
		for (int j = 0; j < STORAGE_SIZE.y; j++)
			storage[i][j] = new ItemInStorage();

	rect.setSize(STORAGE_SIZE_OPEN);
	rect.setPosition(WIN_SIZE * 0.5f - STORAGE_SIZE_OPEN * 0.5f);
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(Type::STORAGE));
}

Storage::~Storage()
{
	for (int i = 0; i < STORAGE_SIZE.x; i++)
		for (int j = 0; j < STORAGE_SIZE.y; j++)
			delete storage[i][j];

	for (int i = 0; i < MAP_SIZE.x; i++)
		delete storage[i];

	delete storage;
	storage = 0;
}

void Storage::Open()
{
	open = !open;
}

void Storage::Draw(sf::RenderWindow* win)
{
	if (open)
	{
		sf::Vector2f shift = rect.getPosition() + sf::Vector2f{19, 19};
		win->draw(rect);
		for (int i = 0; i < STORAGE_SIZE.x; i++)
			for (int j = 0; j < STORAGE_SIZE.y; j++)
				storage[i][j]->Draw(win, shift + sf::Vector2f{ 57.f * i,57.f * j });
	}
}

void Storage::Move(sf::Vector2f shift)
{
	rect.move(shift);
}

//Возврат сколько не поместилось
int Storage::PutItemAuto(Type type, int count)
{
	for (int j = 0; j < STORAGE_SIZE.y; j++)
		for (int i = 0; i < STORAGE_SIZE.x; i++)
		{
			count -= storage[i][j]->PutItem(type, count);
			if (count <= 0)
				return count;
		}

	return count;
}


